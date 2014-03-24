#include "com.h"
#include <string>

bool Com::comListNGRead(){
	if(mh.recieveCode()==Protocol::COM_END){
		return true;
	}else{
		return false;
	}

}

bool Com::readCreateNG(string& str){
	str=mh.recieveStringParameter();
	if(mh.recieveCode()==Protocol::COM_END){
		return true;
	}else{
		return false;
	}
}

bool Com::readDeleteNG(int& nbr){
	nbr=mh.recieveIntParameter();
	if(mh.recieveCode()==Protocol::COM_END){
		return true;
	}else{
		return false;
	}
}

bool Com::readListArtCmd(int& nbr){
	nbr=mh.recieveIntParameter();
	if(mh.recieveCode()==Protocol::COM_END){
		return true;
	}else{
		return false;
	}

}

bool Com::createArtRead(int& nbr,string& title,string& author,string& text){
  nbr= mh.recieveIntParameter();
  title=mh.recieveStringParameter();
  author=mh.recieveStringParameter();
  text=mh.recieveStringParameter();
  // ??????????????????????? IF
  if(mh.recieveCode()==Protocol::COM_END){
    return true;
  }else{
    return false;
  }
}

bool Com::deleteArtRead(int& nbr1,int& nbr2){
  nbr1=mh.recieveIntParameter();
  nbr2=mh.recieveIntParameter();
  if(mh.recieveCode()==Protocol::COM_END){
    return true;
  }else{
    return false;
  }
}
