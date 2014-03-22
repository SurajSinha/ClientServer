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