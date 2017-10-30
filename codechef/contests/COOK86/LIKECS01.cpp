#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    string a;
    cin >> a;
    if(a.length() == set<char>(a.begin(), a.end()).size()) cout << "no" << endl;
    else cout << "yes" << endl;
  }
}

