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
 std:: vector<Article> readAnsListArt();
 bool readCreateArt();
 size_t readDeleteArt();
 Article readGetArt();
 private:
  MessageHandler mh;
};
#endif
