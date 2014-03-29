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
    return v;
  }else{
    throw ProtocolViolationException();//Ska också client göra detta?
  }
}

string Ans::readAnsCreateNG(){
  if(mh.recieveCode()==Protocol::ANS_CREATE_NG){
    size_t answer=mg.recieveCode();
    if(answer==Protocol::ANS_NAK){
      size_t errorCode=mg.recieveCode();
      string str=to_string(errorCode);
      return str;
    }else{
      return to_string(answer);
    }
  }else{
    throw ProtocolViolationException();
  }
}
