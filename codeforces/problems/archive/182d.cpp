#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.length(),
      m = b.length();
  vector<int> divisors;
  for(int i = 1; i <= n; i++)
    if(n%i == 0) divisors.push_back(i);
  int cnt = 0;
  for(int div: divisors){
    if(m%div == 0){
      bool flag = true;
      for(int i = 0; i < n; i++){
        if(a[i] != a[i%div]){
          flag = false;
          break;
        }
      }
      for(int i = 0; i < m; i++){
        if(b[i] != a[i%div]){
          flag = false;
          break;
        }
      }
      if(flag) cnt++;
    }
  }
  cout << cnt << endl;
}

