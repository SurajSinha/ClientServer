#include "com.h"
#include <string>
using namespace std;


bool Com::comListNGRead(){
	return mh.recieveCode()==Protocol::COM_END;
	
}

bool Com::readCreateNG(string& str){
	str=mh.recieveStringParameter();
	return mh.recieveCode()==Protocol::COM_END;
}

bool Com::readDeleteNG(size_t& nbr){
	nbr=mh.recieveIntParameter();
	return mh.recieveCode()==Protocol::COM_END;
	
}

bool Com::readListArtCmd(size_t& nbr){
	nbr=mh.recieveIntParameter();
	return mh.recieveCode()==Protocol::COM_END;
	

}

bool Com::createArtRead(size_t& nbr,string& title,string& author,string& text){
  nbr= mh.recieveIntParameter();
  title=mh.recieveStringParameter();
  author=mh.recieveStringParameter();
  text=mh.recieveStringParameter();
  // ??????????????????????? IF
  return mh.recieveCode()==Protocol::COM_END;
 
}

bool Com::deleteArtRead(size_t& ngId,size_t& aId){
  aId=mh.recieveIntParameter();
  ngId=mh.recieveIntParameter();
  return mh.recieveCode()==Protocol::COM_END;
}

bool Com::readGetArtCmd(size_t& ngId,size_t& aId){
  ngId=mh.recieveIntParameter();
  aId=mh.recieveIntParameter();
  return mh.recieveCode()==Protocol::COM_END;
}

