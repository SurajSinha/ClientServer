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
/*	/* format:
			
			lastid \n
			ngname \n
			ngid numarticles \n
			article1_name \n
			article1_id article1_textsize \n
			text[article1_textsize]
			article2_name \n
			article2_id  article2_textsize \n
			text[article2_textsize]
	*/


	ifstream file("awesome.txt");

	
	file>>lastId;

	while(file)
	{		
		int ngid;
		string ngname;
		int nArt;

		getline(file,ngname);
		file>>ngid;		
		file>>nArt;

		NewsGroup* ng=new NewsGroup(ngid,ngname);

		for(size_t i=0;i<nArt;i++)
		{
			int artId;
			string artName;
			int len;
			
			getline(file,ngname);
			file>>artId;			
			file>>len;

			char* str=new char[len];
			file.get(str,len);
			string text(str);
			delete str;

			auto a=make_shared<Article>();
			a->id=artId;
			a->title=artName;
			a->contents=text;
			ng->addArticle(a);
		}

		shared_ptr<NewsGroup> sng(ng);
		mapId[ng->id]=sng;
		mapName[ng->name]=sng;
	}
}
void Database::save(){
	ofstream file("awesome.txt");
	if(!file)return;

	file<<lastId<<endl;
	for(auto ngp:mapId)
	{
		auto ng=ngp->second;
		file << ng->name <<endl 
		     << ng->id << " " << ng->nbrArticles << endl;
		
		auto end=ng->articleEnd();
		for(auto it=ng->articleBegin();it!=end;++it)
		{
			file<<it->second->title<<endl
				<<it->second->id<<" "<<it->second->contents.size()<<endl
				<<text<<endl;
		}
	}
}
