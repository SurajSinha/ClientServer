#include "ans.h"
#include <string>
using namespace std;

void Ans::readAnsListNG(size_t& id, string& name){
  mh.sendCode(Protocol::ANS_LIST_NG);
  mh.sendNumParamater(id);
  mh.sendStringParameter(name);
  mh.sendCode(Protocol::COM_END);
}
