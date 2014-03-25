#include "com.h"
#include <string>

bool Com::comListNGRead(){
	return mh.recieveCode()==Protocol::COM_END;
	
}

bool Com::readCreateNG(string& str){
	str=mh.recieveStringParameter();
	return mh.recieveCode()==Protocol::COM_END;
}

bool Com::readDeleteNG(int& nbr){
	nbr=mh.recieveIntParameter();
	return mh.recieveCode()==Protocol::COM_END;
	
}

bool Com::readListArtCmd(int& nbr){
	nbr=mh.recieveIntParameter();
	return mh.recieveCode()==Protocol::COM_END;
	

}

bool Com::createArtRead(int& nbr,string& title,string& author,string& text){
  nbr= mh.recieveIntParameter();
  title=mh.recieveStringParameter();
  author=mh.recieveStringParameter();
  text=mh.recieveStringParameter();
  // ??????????????????????? IF
  return mh.recieveCode()==Protocol::COM_END;
 
}

bool Com::deleteArtRead(int& nbr1,int& nbr2){
  nbr1=mh.recieveIntParameter();
  nbr2=mh.recieveIntParameter();
  return mh.recieveCode()==Protocol::COM_END;
}

bool Com::readGetArtCmd(int& ngId,int& aId){
  ngId=mh.recieveIntParameter();
  aId=mh.recieveIntParameter();
  return mh.recieveCode()==Protocol::COM_END;


}
