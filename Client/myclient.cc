#include "com.h"
#include "ans.h"
int main(){
  MessageHandler mh;
  Com com(mh);
  Ans ans(mh);

  return 0;
}
