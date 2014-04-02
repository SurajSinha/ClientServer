#ifndef COM_H
#define COM_H
#include <string>
#include "handler.h"
	class Com{
	public:
		Com(MessageHandler &m):mh(m){}
		bool ListNGRead();
		bool readCreateNG(std::string& str);
		bool readDeleteNG(size_t& nbr);
		bool readListArtCmd(size_t& nbr);
		bool createArtRead(size_t& nbr,std::string& title,std::string& author,std::string& text);
		
		bool deleteArtRead(size_t& nbr1,size_t& nbr2);
		bool readGetArtCmd(size_t& nbr1,size_t& nbr2);
	private:
		MessageHandler mh;
		
	};
#endif
