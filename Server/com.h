#ifndef ANS_H
#define ANS_H
#include <string>
#include "article.h"
	class Com{
	public:
		Com(MessageHandler &m):mh(m){}
		bool comListNGRead();
		bool readCreateNG(string& str);
		bool readDeleteNG(int& nbr);
		bool createArtRead(int& nbr,string& title,string& author,string& text);
		bool readListArtCmd(int& nbr);
		bool deleteArtRead(int& nbr1,int &nbr2);
	private:
		MessageHandler mh;
		
	}
#endif
