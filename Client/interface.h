#ifndef INTERFACE_H
#define INTERFACE_H
#include "com.h"
#include "ans.h"
class interface{
public:
  interface(Com& com, Ans& ans):c(com), a(ans){}
  int main();
private:
  Com c;
  Ans a; 
};
#endif
