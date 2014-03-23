#ifndef NEWSGROUP_H__
#define NEWSGROUP_H__


#include <map>
#include <utility>
#include "exceptions.h"
#include <iostream>
using namespace std;
class NewsGroup{
public:
size_t nbrArticles;
size_t id;
string name;

NewsGroup();
NewsGroup(size_t id, string nm);
void deleteArticle(size_t id);
shared_prt<Article> getArticle(size_t id);
auto articleBegin();
auto articleEnd();
private:
map<size_t, shared_ptr<Article> > map;
};
#endif
