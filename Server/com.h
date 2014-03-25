#ifndef COM_H
#define COM_H
#include <string>
#include "handler.h"
	class Com{
	public:
		Com(MessageHandler &m):mh(m){}
		bool comListNGRead();
		bool readCreateNG(std::string& str);
		bool readDeleteNG(int& nbr);
		bool readListArtCmd(int& nbr);
		bool createArtRead(int& nbr,std::string& title,std::string& author,std::string& text);
		
		bool deleteArtRead(size_t& nbr1,size_t& nbr2);
		bool readGetArtCmd(int& ngId,int& aId);
	private:
		MessageHandler mh;
		
	};
#endif
