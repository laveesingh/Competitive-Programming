#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  long long n = a.length();
  vector<long long> ind1, ind2;
  for(long long i = 0; i < n; i++){
    if(i+5 <= n && a.substr(i, 5) == "heavy"){
      ind1.push_back(i);
    }
    if(i+5 <= n && a.substr(i, 5) == "metal"){
      ind2.push_back(i);
    }
  }
  long long ans = 0;
  for(long long i: ind1){
    long long lb = lower_bound(ind2.begin(), ind2.end(), i) - ind2.begin();
    ans += ind2.size() - lb;
  }
  cout << ans << endl;
}

