#ifndef DATABASE_H__
#define DATABASE_H__
#include "newsGroup.h"
#include "article.h"
#include <memory>
#include <map>
#include <string>
#include <vector>
class Database {
	public:
	typedef std::map<size_t, std::shared_ptr<NewsGroup> >::iterator articleItr;
//	typedef newsGroupIterator newsItr;
	Database();
	~Database();
	void newArticle(std::shared_ptr<Article> article);
	size_t newNewsGroup(std::shared_ptr<NewsGroup> newsGroup);
	std::shared_ptr<Article> getArticle(size_t articleID, size_t newsGroupID);
	void deleteArticle(size_t articleID, size_t newsGroupID);
	articleItr newsGroupBegin();
	articleItr newsGroupEnd();
	void load();
	void save();
	std::vector<Article> getArticles(size_t n);
	size_t deleteNewsGroup(size_t newsGroupID);
	size_t createNewsGroup(size_t newsGroupID, std::string name);
	
	size_t createArticle(size_t nbr, std::string title, std::string author, std::string text);
	size_t createNG(std::string name);
	
	size_t NewsGroupDoesNotExist = 51;
	size_t NewsGroupExists = 52;
	size_t ACK = 28; 
	private:
	bool loadswitch = false;
	size_t nbrOfNewsGroups = 1;
	std::map<std::string, std::shared_ptr<NewsGroup> > mapName;
	std::map<size_t, std::shared_ptr<NewsGroup> > mapId;
};
#endif
