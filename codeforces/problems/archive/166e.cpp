#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int na, nb, nc, nd, pa, pb, pc, pd;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  pa = pb = pc = 1, pd = 0;
  for(int i = 2; i <= n; i++){
    na = ((pb + pc) % MOD + pd) % MOD;
    nb = ((pa + pc) % MOD + pd) % MOD;
    nc = ((pa + pb) % MOD + pd) % MOD;
    nd = ((pa + pb) % MOD + pc) % MOD;
    pa = na, pb = nb, pc = nc, pd = nd;
  }
  if(n == 1)
    cout << pd << endl;
  else
    cout << nd << endl;
}

