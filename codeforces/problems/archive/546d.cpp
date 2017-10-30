#include <bits/stdc++.h>

using namespace std;

const int N = 5 * 1e6 + 1;
int spf[N], npf[N];
int psum[N];

void set_smallest_prime_factor(){
  for(int i = 0; i < N; i += 1)
    spf[i] = i%2 ? i : 2;
  for(int i = 3; i < N; i += 2) if(spf[i] == i)
      for(int j = i; j < N; j += i)
        spf[j] = min(spf[j], i);
}

void set_number_prime_factors(){
  for(int i = 2; i < N; i+= 1){
    int num = i, pfs = 0;
    while(num > 1){
      num /= spf[num];
      pfs++;
    }
    npf[i] = pfs;
  }
}




int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b;
  set_smallest_prime_factor();
  set_number_prime_factors();
  for(int i = 2; i < N; i++) psum[i] = psum[i-1] + npf[i];
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    printf("%d\n", psum[a]-psum[b]);
  }
}

