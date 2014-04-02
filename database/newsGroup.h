#ifndef NEWSGROUP_H__
#define NEWSGROUP_H__


#include <map>
#include <utility>
#include "exceptions.h"
#include "article.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class NewsGroup{
public:
typedef std::map<size_t, std::shared_ptr<Article> >::iterator itr;
size_t nbrArticles;
size_t id;
std::string name;

NewsGroup();
NewsGroup(size_t id, std::string nm);
void deleteArticle(size_t id);
std::shared_ptr<Article> getArticle(size_t id);
itr articleBegin();
itr articleEnd();
void addArticle(std::shared_ptr<Article> a);
size_t getSize(){return map.size();}
private:
std::map<size_t, std::shared_ptr<Article> > map;
};
#endif
