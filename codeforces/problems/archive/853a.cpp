#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int> 

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int c[n];
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }
  set<pii> costs;
  set<int> minutes;
  int total = 0;
  for(int i = 1+k; i < n+k; i++) minutes.insert(i);
  for(int i = 0; i < n; i++) costs.insert({c[i], i+1});
  cerr << "costs size: " << costs.size() << endl;
  int ans[n+k+1];
  while(!minutes.empty()){
    pii cost = *(costs.rbegin());
    int ind = cost.second;
    cerr << "For cost: " << cost.first << " " << cost.second << endl;
    if(minutes.find(ind) != minutes.end()) {
      cerr << "Is safe " << ind << endl;
      costs.erase(cost);
      minutes.erase(ind);
      ans[ind] = ind;
    }else{
      int minute = *minutes.begin();
      minutes.erase(minute);
      total += cost.first * (minute-ind);
      costs.erase(cost);
      ans[ind] = minute;
      cerr << "minute: " << minute << " assigned" << endl;
    }
  }
  cout << total << endl;
  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << endl;
}

