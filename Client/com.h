#ifndef COM_H
#define COM_H
#include <string>
#include "handler.h"

class Com{
 public:
 Com(MessageHandler& m):mh(m){}
  void sendListNG();
  void sendCreateNG(std::string& str);
  void sendDeleteNG(size_t& id);
  void sendListArt(size_t& id);
  void sendCreateArt(size_t& id,std::string& title,std::string& author,std::string& text);
  void sendDeleteArt(size_t& ngId, size_t& artId);
  void sendGetArt(size_t& ngId, size_t& artId);
 private:
  MessageHandler mh;
};
#endif
