#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin  >> n >> k;
  int total = 240;
  total -= k;
  int taken = 0, max_prob = 0;
  for(int i = 1; i <= n; i++){
    taken += 5 * i;
    if(taken <= total) max_prob = i;
  }
  cout << max_prob << endl;
}

