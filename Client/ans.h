#ifndef ANS_H
#define ANS_H
#include <string>
#include "handler.h"

class Ans{
 public:
 Ans(MessageHandler& m):mh(m){}
 void readAnsListNG(size_t& id, std::string& name);
 private:
  MessageHandler mh;
};
#endif
