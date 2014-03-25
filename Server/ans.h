#ifndef ANS_H
#define ANS_H
#include <vector>
#include "newsGroup.h"
#include <memory>
#include "handler.h"
#include "article.h"
	class Ans{
	public:
		Ans(MessageHandler& m):mh(m){}
		void sendListNg(std::vector<NewsGroup>& ngs);
		void sendResponseToCreateNG();
		void sendResponseToDeleteNG();
		void sendResponseToListArt(std::vector<Article>& art);
		void sendResponseToCreateArt();
		
		void sendResponseToDeleteArt();
		void sendResponseToGetArt(std::shared_ptr<Article> ptr);
		size_t  errorCode;
		size_t  answer;
	private:
		MessageHandler mh;
		
	};
#endif
