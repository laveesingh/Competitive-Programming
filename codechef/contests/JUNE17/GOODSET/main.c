#include <stdio.h>

int main(void){
  int t, n;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      printf("%d ", 2*i+1);
    printf("\n");
  }
}
