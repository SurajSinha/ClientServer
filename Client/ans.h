#ifndef ANS_H
#define ANS_H
#include <string>
#include "handler.h"
#include <vector>
#include "article.h"
#include "newsGroup.h"
#include <memory>
class Ans{
 public:
 Ans(MessageHandler& m):mh(m){}
 std::vector<NewsGroup> readAnsListNG();
 bool readAnsCreateNG();
 bool readAnsDeleteNG();
 std:: vector<Article> readAnsListArt();
 bool readCreateArt();
 size_t readDeleteArt();
 
 // std::pair<size_t,std::shared_ptr<Article>> readGetArt();
 private:
  MessageHandler mh;
};
#endif
