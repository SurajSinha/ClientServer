#include "ans.h"

using namespace std;

vector<NewsGroup> Ans::readAnsListNG(){
  if(mh.recieveCode()==Protocol::ANS_LIST_NG){
    vector<NewsGroup> v;
    int nbrOfItems=mh.recieveIntParameter();
    for(int i = 0; i != nbrOfItems; ++i){
      int id=mh.recieveIntParameter();
      string title=mh.recieveStringParameter();
      v.push_back(NewsGroup(id,title));
    }
    mh.recieveCode();
    return v;
  }else{
    throw ProtocolViolationException();//Ska också client göra detta?
  }
}

bool Ans::readAnsCreateNG(){
  if(mh.recieveCode()==Protocol::ANS_CREATE_NG){
    size_t answer=mh.recieveCode();
    if(answer==Protocol::ANS_NAK){
      size_t errorCode=mh.recieveCode();
       mh.recieveCode();
      return false;
    }else{
      mh.recieveCode();
      return true;
    }
  }else{
    throw ProtocolViolationException();
  }
}

bool Ans::readAnsDeleteNG(){
  if(mh.recieveCode()==Protocol::ANS_DELETE_NG){
    size_t answer=mh.recieveCode();
    if(answer==Protocol::ANS_NAK){
      size_t errorCode=mh.recieveCode();
      mh.recieveCode();
      return false;
    }else{
      mh.recieveCode();
      return true;
    }
  }else{
    throw ProtocolViolationException();
  }
}

vector<Article> Ans::readAnsListArt(){
  if(mh.recieveCode()==Protocol::ANS_LIST_ART){
    size_t answer=mh.recieveCode();
    vector<Article> v;
    if(answer==Protocol::ANS_ACK){
      int nbrOfItems=mh.recieveIntParameter();
     
      for(int i = 0; i!= nbrOfItems; ++i){
	int id=mh.recieveIntParameter();
	string title=mh.recieveStringParameter();
	v.push_back(Article(id,title));
      }
	  mh.recieveCode();
	  return v;
    }else{
      size_t errorCode=mh.recieveCode();
	mh.recieveCode();
	
	return  v;
    }
  }else{
    throw ProtocolViolationException();
  }
}

bool Ans::readCreateArt(){
  if(mh.recieveCode()==Protocol::ANS_CREATE_ART){
    size_t answer = mh.recieveCode();
    mh.recieveCode();//Recieve ANS_END
    return answer == Protocol::ANS_ACK;
  }else{
    throw ProtocolViolationException();
  }
}

size_t Ans::readDeleteArt(){
  if(mh.recieveCode()==Protocol::ANS_DELETE_ART){
    size_t answer = mh.recieveCode();
    mh.recieveCode();//Recieve ANS_END
    return answer;
  }else{
    throw ProtocolViolationException();
  }
}/*
pair<size_t,shared_ptr<Article>> Ans::readGetArt(){
   if(mh.recieveCode()==Protocol::ANS_GET_ART){
    size_t answer = mh.recieveCode();
    if(answer == Protocol::ANS_ACK){
      string title = mh.recieveStringParameter();
      string author = mh.recieveStringParameter();
      string text = mh.recieveStringParameter();
      shared_ptr<Article> art=make_shared<Article>(title,author,text);
      return make_pair(answer,art);
    }else{
      shared_ptr<Article> art;
      return make_pair(answer,art);
    }
  }else{
    throw ProtocolViolationException();
  }




}
 */
