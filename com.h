#ifndef ANS_H
#define ANS_H
#include <string>
	class Com{
	public:
		Com(MessageHandler &m):mh(m){}
		bool comListNGRead();
		bool readCreateNG(string& str);
		bool readDeleteNG(int& nbr);
	
	private:
		MessageHandler mh;
		
	}
#endif