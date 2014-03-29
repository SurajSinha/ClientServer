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
    mg.recieveCode();
    return v;
  }else{
    throw ProtocolViolationException();//Ska också client göra detta?
  }
}

bool Ans::readAnsCreateNG(){
  if(mh.recieveCode()==Protocol::ANS_CREATE_NG){
    size_t answer=mg.recieveCode();
    if(answer==Protocol::ANS_NAK){
      size_t errorCode=mg.recieveCode();
       mg.recieveCode();
      return false;
    }else{
      mg.recieveCode();
      return true;
    }
  }else{
    throw ProtocolViolationException();
  }
}

bool Ans::readAnsDeleteNG(){
  if(mh.recieveCode()==Protocol::ANS_DELETE_NG){
    size_t answer=mg.recieveCode();
    if(answer==Protocol::ANS_NAK){
      size_t errorCode=mg.recieveCode();
      mg.recieveCode();
      return false;
    }else{
      mg.recieveCode();
      return true;
    }
  }else{
    throw ProtocolViolationException();
  }
}

