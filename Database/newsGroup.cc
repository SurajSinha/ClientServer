#ifndef NEWSGROUP_H__
#define NEWSGROUP_H__


#include <map>
#include <utility>
#include "exceptions.h"
#include <iostream>
#include "newsgroup.h"
using namespace std;
newsGroup::newsGroup(){}
newsGroup::newsGroup(size_t i, string s): id(i), name(s){}
void newsGroup::addArticle(shared_ptr<Article> a){
	a->id = ++nbrArticles;
	map.insert(make_pair(a->id, a));
}
shared_prt<Article> newsGroup::getArticle(size_t id){
	auto it = map.find(id);
	if(it==map.end(){
		throw ArticleNonExistentException();
	}
return it->second;
}
void newsGroup::deleteArticle(size_t id){
	auto it = articles.find(id);
	if(it==articles.end()){
		throw ArticleNonExistentException();
	}
	map.erase(id);
}

auto newsGroup::articleBegin(){
	return map.begin();
}

auto newsGroup::articleEnd(){
	return map.end();
}
