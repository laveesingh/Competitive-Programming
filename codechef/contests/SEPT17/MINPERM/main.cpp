#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    int st = 1;
    vector<int> ans;
    while(st < n){
      if(st + 2 == n){
        ans.push_back(st+1);
        ans.push_back(st+2);
        ans.push_back(st);
      }else{
        ans.push_back(st+1);
        ans.push_back(st);
      }
      st += 2;
    }
    for(int s: ans) cout << s << " ";
    cout << endl;
  }
}

