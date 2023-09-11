#include<stdio.h>


int multr(int a, int b){
  if (a==0){
    return 0;
  }

  return multr((a-1), b)+b;
}



int main(){
  int a;
  int b;
  a = 2;
  b = 4;
  int r;
  printf("%i", multr(a,b));
  return 0;
}
















