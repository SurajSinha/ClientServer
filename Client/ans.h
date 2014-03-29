#ifndef ANS_H
#define ANS_H
#include <string>
#include "handler.h"
#include <vector>
#include "newsGroup.h"
class Ans{
 public:
 Ans(MessageHandler& m):mh(m){}
 std::vector<NewsGroup> readAnsListNG();
 std::string readAnsCreateNG();
 private:
  MessageHandler mh;
};
#endif
