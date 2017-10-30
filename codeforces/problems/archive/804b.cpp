#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  int n = a.length();
  vector<int> a_index;
  for(int i = 0; i < n; i++) if(a[i] == 'a') 
    a_index.push_back(i);
  reverse(a_index.begin(), a_index.end());
  //for(int ind: a_index) cerr << ind << endl;
  int no_b = 0, steps = 0, cur_b;
  for(int i = 0; i < a_index.size(); i++){
    if(i == 0)
      cur_b = (no_b + a.length() - a_index[i] - 1) % MOD;
    else
      cur_b = (no_b + a_index[i-1] - a_index[i] - 1) % MOD;
    steps = (steps + cur_b) % MOD;
    no_b = (cur_b * 2) % MOD;
  }
  cout << steps << endl;
}

