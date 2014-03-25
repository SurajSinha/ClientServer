#ifndef ANS_H
#define ANS_H
	class Ans{
	public:
		Ans(MessageHandler &m):mh(m){}
		bool sendListNg(vector<Newsgroup>& ngs);
		void sendResponseToCreateNG();
		void sendResponseToDeleteNG();
		void sendResponseToListArt(vector<Article>& art);
		void sendResonseToCreateArt();
		//bool sendListArt(vector<Newsgroup>& ngs);
		void sendResponseToDeleteArt();
		void sendResponseToGetArt(shared_ptr<Article> ptr);
		size_t  errorCode;
		size_t  answer;
	private:
		MessageHandler mh;
		
	}
#endif
