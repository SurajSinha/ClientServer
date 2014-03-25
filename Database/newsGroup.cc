
#include <map>
#include <utility>
#include "exceptions.h"
#include <iostream>
#include <memory>
#include "newsGroup.h"
using namespace std;
NewsGroup::NewsGroup(){}
NewsGroup::NewsGroup(size_t i, string s): id(i), name(s){}
void NewsGroup::addArticle(shared_ptr<Article> a){
	++nbrArticles;
	a->id = nbrArticles;
	map.insert(make_pair(a->id, a));
}
shared_ptr<Article> NewsGroup::getArticle(size_t id){
	auto it = map.find(id);
	if(it==map.end()){
		throw ArticleNonExistentException();
	}
return it->second;
}
void NewsGroup::deleteArticle(size_t id){
	auto it = map.find(id);
	if(it==map.end()){
		throw ArticleNonExistentException();
	}
	map.erase(id);
}

NewsGroup::itr NewsGroup::articleBegin(){
	return map.begin();
}

NewsGroup::itr NewsGroup::articleEnd(){
	return map.end();
}
