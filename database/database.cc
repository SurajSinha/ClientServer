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



int readInt(ifstream& file)
{
	int v;
	file>>v;
	return v;
}
string readStr(ifstream& file)
{
	int s=readInt(file);	
	char* str=new char[s+1];	
	file.ignore(1);
	file.get(str,s+1,0);
	string text(str);
	return text;
}
void saveInt(ofstream& file,int v)
{
	file<<v<<" ";
}
void saveStr(ofstream& file,string &str)
{
	saveInt(file,str.size());
	file<<str<<" ";
}


void Database::load(){

	ifstream file("awesome.txt");	
	size_t numNG=readInt(file);
	for(size_t j=0;j<numNG;j++)
	{	
		
		string ngname=readStr(file);
		size_t  ngid=readInt(file);		
		size_t  nArt=readInt(file);
		size_t  lastArtId=readInt(file);

		NewsGroup* ng=new NewsGroup(ngid,ngname);
		ng->nbrArticles=lastArtId;
		cout<<"ngname:"<<ngname<<endl;
		cout<<"ngid:"<<ngid<<endl;
		cout<<"nArt:"<<nArt<<endl;
		
		for(size_t i=0;i<nArt;i++)
		{
			string artName=readStr(file);
			string author=readStr(file);
			size_t artId=readInt(file);
			string text=readStr(file);

			
			cout<<"artname:"<<artName<<endl;
			cout<<"artname:"<<author<<endl;
			cout<<"artId:"<<artId<<endl;			
			cout<<"text:"<<text<<endl;

			auto a=make_shared<Article>();
			a->id=artId;
			a->title=artName;
			a->contents=text;
			a->writer=author;
			ng->addArticle(a);

		}
		
		shared_ptr<NewsGroup> sng(ng);
		mapId[ng->id]=sng;
		mapName[ng->name]=sng;
	}
}
void Database::save(){
	ofstream file("awesome.txt");
 	saveInt(file,mapId.size());
	for(auto ngp:mapId)
	{
		auto ng=ngp.second;
		saveStr(file,ng->name);
		saveInt(file,ng->id);
		saveInt(file,ng->getSize());
		saveInt(file,ng->nbrArticles);
		auto end=ng->articleEnd();
		for(auto it=ng->articleBegin();it!=end;++it)
		{
			saveStr(file,it->second->title);
			saveStr(file,it->second->writer);
			saveInt(file,it->second->id);
			saveStr(file,it->second->contents);			
		}
	
	}
		

	return;
}
