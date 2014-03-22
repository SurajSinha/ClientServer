#ifndef DATABASE_H__
#define DATABASE_H__
#include "newsgroup.h"
#include "article.h"
template <typename articleIterator, typename newsGroupIterator>
class Database {
	public:
	typedef articleIterator articleItr;
	typedef newsGroupIterator newsItr;
	Database();
	~Database();
	void newArticle(shared_ptr<Article> article);
	void newNewsGroup(shared_ptr<NewsGroup> newsGroup);
	shared_ptr<Article> getArticle(size_t articleID, size_t newsGroupID);
	void deleteArticle(size_t articleID, size_t newsGroupID);
	newsItr newsGroupBegin();
	newsItr newsGroupEnd();
	void load();
	void save();
	
	vector<Article> getArticles(size_t n);
	size_t deleteNewsGroup(size_t newsGroupID);
	size_t createNewsGroup(size_t newsGroupID, string name);
	
	private:
	bool loadswitch = false;
	size_t nbrOfNewsGroups = 1;
	map<string, shared_ptr<NewsGroup> > mapName;
	map<size_t, shared_ptr<NewsGroup> > mapId;
};
#endif
