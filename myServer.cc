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
using namespace std;
void connectionHandler(Server& server, database& db,MessageHandler& mh){
	Ans ans(mh);
	Com com(mh);
	while(true){
		// Nullptr is returned if new Client wishes to communicate.
		auto conn=server.waitForActivity();
		handler.SetConnection(conn);
		if(!conn){
			try{
				// Handle Client Requests.
				string cmd=MessageHandler::recieveCode();
				switch(cmd){
				case Protocol::COM_LIST_NG :
					if(com.comListNGRead()){
						Database::newsItr beg=newsGroupBegin();
						Database::newsItr end=newsGroupEnd();
						if(beg!=end){
							vector<Newsgroup> ngs(beg,end);
							ans.sendListNg(ngs);
						}	
					}
					break;
				case Protocol::COM_CREATE_NG :
					string name;
					if(com.readCreateNG(name)){
						size_t resultCode=db.createNG(name);
						if(resultCode==Protocol::ANS_ACK){
							ans.answer=resultCode;
						}else{
							ans.answer=Protocol::ANS_NAK;
							ans.errorCode=resultCode;
						}
						ans.sendResponseToCreateNG();
						
					}else{
						throw ConnectionClosedException(); //We are closing connection.
					}
				break;
				case Protocol::COM_DELETE_NG :
					
				break;
				case Protocol::COM_LIST_ART :
				
				break;
				case Protocol::COM_CREATE_ART :
				
				break;
				case Protocol::COM_DELETE_ART :
				
				break;
				case Protocol::COM_GET_ART :
				
				break;
				case Protocol::COM_END :
				
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
	if(!server.isReady(){
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
 
 
