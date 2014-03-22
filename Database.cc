#include "database.h"
#include "article.h"
#include "newsgroup.h"

Database::Database{ };
~Database::Database{ };
void Database::newArticle(shared_ptr<Article> article){
	auto it = mapId.find(article->newsGroup);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	it->second->addArticle(article);
};
void Database::newNewsGroup(shared_ptr<NewsGroup> newsGroup){
	auto it = mapName.find(newsGroup->name);
	if(it != mapName.end()){
		throw NewsGroupExistsException();
	}
	newsGroup->id = nbrOfNewsGroups;
	++nbrOfNewsGroups;
	mapName.insert(make_pair(newsGroup->name, newsGroup);
	mapId.insert(make_pair(newsGroup->id, newsGroup);
};
shared_ptr<Article> getArticle(size_t articleID, size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	return it->second->getArticle(articleID);
};
void Database::deleteArticle(size_t articleID, size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	it->second->deleteArticle(articleID);
};
void Database::daleteNewsGroup(size_t newsGroupID){
	auto it = mapId.find(newsGroupID);
	if(it == mapId.end()){
		throw NewsGroupNonExistentException();
	}
	auto it2 = mapName.find(it->second->name);
	mapId.erase(it);
	mapName.erase(it2);
};
newsItr Database::newsGroupBegin(){
	return mapId.begin();
};
newsItr Database::newsGroupEnd(){
	return mapId.end();
};
void Database::load(){
	loadswitch = false;
	ifstream file("awesome.txt");
	string s;
	string n;
	if(file.is_open()){
		while(fin >> s && !loadSwitch){
			if(s=="###Switch### "){
				loadswitch = true;
			}else{
				fin>>n;
				shared_ptr<newsGroup> ptr(n);
				mapName.insert(make_pair(s, ptr));
			}
		}
		while(fin >> s){
			fin>>n;
			shared_ptr<newsGroup> ptr(n);
			istringstream f(s);
			size_t num;
			f>>num;
			mapId.insert(make_pair(num, ptr));
		}
	}
};
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
};
}
