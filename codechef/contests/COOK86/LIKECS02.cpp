#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  wile(t--){
    int n;
    cin >> n;
    if(n > 3) cout << -1 << endl;
    else{
      for(int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    }
  }
}

