#include "com.h"
#include <string>
using namespace std;

void Com::sendListNG(){
  mh.sendCode(Protocol::COM_LIST_NG);
  mh.sendCode(Protocol::COM_END);
}

void Com::sendCreateNG(string& str){
  mh.sendCode(Protocol::COM_CREATE_NG);
  mh.sendStringParameter(str);
  mh.sendCode(Protocol::COM_END);

}

void Com::sendDeleteNG(size_t& id){
  mh.sendCode(Protocol::COM_DELETE_NG);
  mh.sendNumParameter(id);
  mh.sendCode(Protocol::COM_END);
}

void Com::sendListArt(size_t& id ){
  mh.sendCode(Protocol::COM_LIST_ART);
  mh.sendNumParameter(id);
  mh.sendCode(Protocol::COM_END);
}

void Com::sendCreateArt(size_t& id,string& title,string& author,string& text){
  mh.sendCode(Protocol::COM_CREATE_ART);
  mh.sendNumParameter(id);
  mh.sendStringParameter(title);
  mh.sendStringParameter(author);
  mh.sendStringParameter(text);
  mh.sendCode(Protocol::COM_END);
}

void Com::sendDeleteArt(size_t& ngId, size_t& artId){
  mh.sendCode(Protocol::COM_DELETE_ART);
  mh.sendNumParameter(ngId);
  mh.sendNumParameter(artId);
  mh.sendCode(Protocol::COM_END);
}

void Com::sendGetArt(size_t& ngId, size_t& artId){
  mh.sendCode(Protocol::COM_GET_ART);
  mh.sendNumParameter(ngId);
  mh.sendNumParameter(artId);
  mh.sendCode(Protocol::COM_END);
}
