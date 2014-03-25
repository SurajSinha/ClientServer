#include "database.h"
#include "article.h"
#include "newsGroup.h"
#include <fstream>
using namespace std;
Database::Database(){ }
Database::~Database(){ }
void Database::newArticle(shared_ptr<Article> article){
	auto it = mapId.find(article->newsGroup);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	it->second->addArticle(article);
}
vector<Article> Database::getArticles(size_t n){
	vector<Article> a;
	auto it = mapId.find(n);
	if(it==mapId.end()){
		throw NewsGroupNonExistentException();
	}
	auto start = it->second->articleBegin();
	auto end = it->second->articleEnd();
	while(start!=end){
		a.push_back(*start->second);
		++start;
	}
	return a;
	
}
size_t Database::newNewsGroup(shared_ptr<NewsGroup> newsGroup){
	auto it = mapName.find(newsGroup->name);
	if(it != mapName.end()){
		return NewsGroupExists;
	}
	newsGroup->id = nbrOfNewsGroups;
	++nbrOfNewsGroups;
	mapName.insert(make_pair(newsGroup->name, newsGroup));
	mapId.insert(make_pair(newsGroup->id, newsGroup));
	return ACK;
}
shared_ptr<Article> Database::getArticle(size_t articleID, size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	return it->second->getArticle(articleID);
}
void Database::deleteArticle(size_t articleID, size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	it->second->deleteArticle(articleID);
}
size_t Database::deleteNewsGroup(size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		return NewsGroupExists;
	}
	auto it2 = mapName.find(it->second->name);
	mapId.erase(it);
	mapName.erase(it2);
	return ACK;
}

Database::articleItr Database::newsGroupBegin(){
	return mapId.begin();
}
Database::articleItr Database::newsGroupEnd(){
	return mapId.end();
}
size_t Database::createArticle(size_t nbr, string title, string author, string text){
	auto it = mapId.find(nbr);
	if(it == mapId.end()){
		return NewsGroupDoesNotExist;
	}
	
	shared_ptr<Article> ptr(new Article);
	ptr->title = title;
	ptr->writer = author;
	ptr->contents = text;
	ptr->newsGroup = nbr;
	
	it->second->addArticle(ptr);
	return ACK;
}
size_t Database::createNG(string name){
	auto it = mapName.find(name);
	if(it != mapName.end()){
		return NewsGroupExists;
	}
	size_t id = nbrOfNewsGroups;
	++nbrOfNewsGroups;
	shared_ptr<NewsGroup> ptr(new NewsGroup);
	ptr->name = name;
	ptr->id=id;
	mapName.insert(make_pair(name, ptr));
	mapId.insert(make_pair(id, ptr));
	return ACK;
}
void Database::load(){
/*	loadswitch = false;
	ifstream file("awesome.txt");
	string s;
	string n;
	if(file.is_open()){
		while(file >> s && !loadswitch){
			if(s=="###Switch### "){
				loadswitch = true;
			}else{
				file>>n;
				
				shared_ptr<NewsGroup> ptr(n);
				mapName.insert(make_pair(s, ptr));
			}
		}
		while(file >> s){
			file>>n;
			shared_ptr<NewsGroup> ptr(n);
			istringstream f(s);
			size_t num;
			f>>num;
			mapId.insert(make_pair(num, ptr));
		}
	}
*/
}
void Database::save(){
ofstream file;
file.open("awesome.txt");
auto it = mapName.begin();
while(it!=mapName.end()){
	file<<it->first<<" "<<it->second<< " ";
	++it;
	}
file<<"###Switch### ";
auto it2 = mapId.begin();
while(it2!=mapId.end()){
	file<<it2->first<<" "<<it2->second<<" ";
	++it2;
	}
file.close();
}
