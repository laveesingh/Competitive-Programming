#include <cstdio>
using namespace std;

int main(void){
  int n, ans = 0, x, q, qtype, qi;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      scanf("%d", &x);
      if(i == j) ans = (ans + x)%2;
    }
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%d", &qtype);
    if(qtype == 3) printf("%d", ans);
    else {
      scanf("%d", &x);
      ans ^= 1;
    }
  }
  printf("\n");
}
