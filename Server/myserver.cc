#include <memory>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

#include "server.h"
#include "connection.h"
#include "handler.h"
#include "connectionclosedexception.h"
#include "ans.h"
#include "com.h"
#include "database.h"
using namespace std;
void connectionHandler(Server& server, Database& db,MessageHandler& mh){

	const bool save=!false;
	if(save)db.load();
  while(true){
    // Nullptr is returned if new Client wishes to communicate.
    auto conn=server.waitForActivity();
    mh.SetConnection(conn);
    if(conn!=nullptr){
      Ans ans(mh);
      Com com(mh);
      try{
	// Handle Client Requests.
	size_t cmd=mh.recieveCode();
	switch(cmd){
	case Protocol::COM_LIST_NG :
	  {
	    if(com.comListNGRead()){
	      auto beg=db.newsGroupBegin();
	      auto end=db.newsGroupEnd();
	      vector <NewsGroup> v;
	      if(beg!=end){
		while(beg!=end){
		  shared_ptr<NewsGroup>ptr= beg->second;
		  v.push_back(*ptr);
		  ++beg;
		}
	      }	
	      ans.sendListNg(v);
	    }else{
	      throw ConnectionClosedException(); //We are closing connection.
	    }
	  }
	  break;
	  
	case Protocol::COM_CREATE_NG :
	  {
	    string name;
	    if(com.readCreateNG(name))
	      {
		size_t resultCode=db.createNG(name);
		if(resultCode==Protocol::ANS_ACK){
		  ans.answer=resultCode;
		  db.save();
		}else{
		  ans.answer=Protocol::ANS_NAK;
		  ans.errorCode=resultCode;
		}
		ans.sendResponseToCreateNG();     
	      }else{
	      throw ConnectionClosedException(); //We are closing connection.
	    }
	  }
	  break;
	case Protocol::COM_DELETE_NG :
	  size_t nbr;
	  if(com.readDeleteNG( nbr)){
	    size_t resultCode=db.deleteNewsGroup(nbr);
	    if(resultCode==Protocol::ANS_ACK){
	      ans.answer=resultCode;
		  if(save)db.save();
	    }else{
	      ans.answer=Protocol::ANS_NAK;
	      ans.errorCode=resultCode;
	    }
	    ans.sendResponseToDeleteNG();
	  }else{
	    throw ConnectionClosedException(); //We are closing connection.
	  }
	  break;
	case Protocol::COM_LIST_ART :
	  if(com.readListArtCmd(nbr)){
	    vector<Article> list;
	    try{
	      list=db.getArticles(nbr);
	      ans.answer=Protocol::ANS_ACK;
	    }catch(NewsGroupNonExistentException e){
	      ans.answer=Protocol::ANS_NAK;
	      ans.errorCode=Protocol::ERR_NG_DOES_NOT_EXIST;		
	    }
	    ans.sendResponseToListArt(list);
	  }else{
	    throw ConnectionClosedException(); //We are closing connection.
	  }
	  break;
	case Protocol::COM_CREATE_ART :
	  {
	    string title,author,text;
	    if(com.createArtRead(nbr,title,author,text)){
	      size_t res=db.createArticle(nbr,title,author,text);
	      ans.answer=res;
	      if(res!=Protocol::ANS_ACK){
		ans.answer=Protocol::ANS_NAK;
		ans.errorCode=Protocol::ERR_NG_DOES_NOT_EXIST;
	      }else 
			{
			if(save) db.save();
			}
	      ans.sendResponseToCreateArt();
	    }else{
	      throw ConnectionClosedException(); //We are closing connection.
	    }
	  }
	  break;
	case Protocol::COM_DELETE_ART :
	  size_t aId,ngId;
	  if(com.deleteArtRead(ngId,aId)){
	    try{
	      db.deleteArticle(ngId,aId);
	      ans.answer=Protocol::ANS_ACK;
		  if(save)db.save();
	    }catch (NewsGroupNonExistentException e1){
	      ans.answer=Protocol::ANS_NAK;
	      ans.errorCode=Protocol::ERR_NG_DOES_NOT_EXIST;
	    }catch (ArticleNonExistentException e2){
	      ans.answer=Protocol::ANS_NAK;
	      ans.errorCode=Protocol::ERR_ART_DOES_NOT_EXIST;
	    }
	    ans.sendResponseToDeleteArt();
	  }else{
	    throw ConnectionClosedException(); //We are closing connection.
	  } 
	  break;
	case Protocol::COM_GET_ART :
	  // int aId,ngId;
	  if(com.readGetArtCmd(ngId,aId)){
	    shared_ptr<Article> res;
	    try{
	      res=db.getArticle(aId,ngId);
	      ans.answer=Protocol::ANS_ACK;
	    }catch(ArticleNonExistentException e1){
	      ans.errorCode=Protocol::ERR_ART_DOES_NOT_EXIST;
	      ans.answer=Protocol::ANS_NAK;
	    }catch(NewsGroupNonExistentException e2){
	      ans.errorCode=Protocol::ERR_NG_DOES_NOT_EXIST;
	      ans.answer=Protocol::ANS_NAK;
	    }		
	    ans.sendResponseToGetArt(res);
	  }else{
	    throw ConnectionClosedException(); //We are closing connection.
	  }
	  break;
	
	case Protocol::COM_END:
	default:
	  throw ConnectionClosedException(); //We are closing connection.
	  break;	
	}		
      }catch(ConnectionClosedException& e){
	server.deregisterConnection(conn);
	cout<<"Client closed Connection"<<endl;
      } 
    }else{
      conn=make_shared<Connection>();
      server.registerConnection(conn);
      cout<<"New client connects"<< endl;
    }
  }
}

int main(int argc, char* argv[]){
  /*
    Checks if number of arguments is 2. If not then program is closed.
  */
  if(argc!=2){
    cerr<<"Usage: myserver port-number" <<endl;
    exit(1);
  }
  /*
    Tries to convert port number in argv array to Integer.
  */
  int port(-1);
  try{
    port=stoi(argv[1]);
  }catch(exception& e){
    cerr<<"Wrong port number."<< e.what()<<endl;
    exit(1);
  }
  /*
    A Server Object is instantiated.
  */
  Server server(port);
  if(!server.isReady()){
    cerr<<"Server initialization Error."<<endl;
    exit(1);
  }
  //Handles connections with the Client.
  Database db;
  MessageHandler handler;

  connectionHandler(server,db,handler);
  // Kommer att göra om denna metod till en 
  //template metod för att hantera db på HDD. 
	
	
}
 
 
