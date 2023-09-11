#include <stdio.h>

int main(){
  int i;
  int sum = 1;
  int n; 
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    sum = sum+(i); 
    printf("%d\n", i);
  }
  printf("The sum is: %d\n", sum);
  return 0;
}




