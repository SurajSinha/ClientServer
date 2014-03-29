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
 bool readAnsCreateNG();
 bool readAnsDeleteNG();

 private:
  MessageHandler mh;
};
#endif
