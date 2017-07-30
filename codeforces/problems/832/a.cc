#include <bits/stdc++.h>

using namespace std;

int main(void){
  long long n, k;
  cin >> n >> k;
  long long cross = n/k;
  if(cross%2) cout << "YES" << endl;
  else cout << "NO" << endl;
}
