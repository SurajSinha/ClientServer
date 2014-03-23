#ifndef ANS_H
#define ANS_H
	class Ans{
	public:
		Ans(MessageHandler &m):mh(m){}
		bool sendListNg(vector<Newsgroup>& ngs);
		void sendResponseToCreateNG();
		void sendResponseToDeleteNG();
		void sendResponseToListArt(vector<Article>& art);
		//bool sendListArt(vector<Newsgroup>& ngs);
		
	
	private:
		MessageHandler mh;
		size_t  errorCode;
		size_t  answer;
	}
#endif
