#include "ans.h"

bool Ans::sendListNg(vector<Newsgroup>& ngs){
  mh.sendCode(Protocol::ANS_LIST_NG); //Typ size_t
  mh.sendNumParameter(ngs.size());
  size_t n=ngs.size();
  for(size_t i=0; i < n;++i){
    mh.sendNumParameter(ngs[i].id);
    mh.sendStringParameter(ngs[i].name);
  }	
  mh.sendCode(Protocol::ANS_END);
}
void Ans::sendResponseToCreateNG(){
  mh.sendCode(Protocol::ANS_CREATE_NG);
  mh.sendCode(answer);
  if(answer!=Protocol::ANS_ACK){
    mh.sendCode(errorCode);
  }
  mh.sendCode(Protocol::ANS_END);
}
void Ans::sendResponseToDeleteNG(){
  mh.sendCode(Protocol::ANS_DELETE_NG);
  mh.sendCode(answer);
  if(answer!=Protocol::ANS_ACK){
    mh.sendCode(errorCode);
  }
  mh.sendCode(Protocol::ANS_END);
}

void Ans::sendResponseToListArt(vector<Article>& art){
  mh.sendCode(Protocol::ANS_LIST_ART);
  mh.sendCode(answer);
  if(answer!=Protocol::ANS_ACK){
    mh.sendCode(errorCode);
  }else{
    size_t n=art.size();
    mh.sendNumParameter(n);
    for(size_t i=0; i < n;++i){
      mh.sendNumParameter(art[i].id);
      mh.sendStringParameter(art[i].title);
    }	
    mh.sendCode(Protocol::ANS_END);
  }
}
void Ans::sendResponseToCreateArt(){
  mh.sendCode(Protocol::ANS_CREATE_ART);
  mh.sendCode(answer);
  if(answer!=Protocol::ANS_ACK){
    mh.sendCode(errorCode);
  }
  mh.sendCode(Protocol::ANS_END);
}
void Ans::sendResponseToDeleteArt(){
  mh.sendCode(Protocol::ANS_DELETE_ART);
  mh.sendCode(answer);
  if(answer!=Protocol::ANS_ACK){
    mh.sendCode(errorCode);
  }
  mh.sendCode(Protocol::ANS_END);
}

void Ans::sendResponseToGetArt(shared_ptr<Article> ptr){
  mh.sendCode(Protocol::ANS_GET_ART);
  mh.sendCode(answer);
  if(answer==Protocol::ANS_ACK){
    sendStringParameter(ptr->title);
    sendStringParameter(ptr->writer);
    sendStringParameter(ptr->contents);
  }else{
    mh.sendCode(errorCode);
  }
  mh.sendCode(Protocol::ANS_END);

}

