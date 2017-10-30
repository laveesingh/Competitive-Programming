#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if(n >= m){
    if(n > m+1){
      cout << -1 << endl;
    }else{ 
      for(int i = 0; i < m; i++)
        cout << "01";
      if(n > m) cout << "0" << endl;
      else cout << endl;
    }
  }else{
    if(m > 2*n+2){
      cout << -1 << endl;
    }else{
      int x = m - n;
      for(int i = 0; i < min(x, n); i++) cout << "110";
      if(x < n) for(int i = x; i < n; i++) cout << "10";
      if(m == 2*n+1) cout << "1";
      if(m == 2*n+2) cout << "11";
      cout << endl;
    }
  }
}

