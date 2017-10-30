#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
const int N = 1e4 + 1;
const int inf = 2e9;
int n;
int assis[N], capt[N], suff_capt[N];
map<pii, int> store;

int solve(int i, int ass){
  if(store[make_pair(i, ass)]) return store[make_pair(i, ass)];
  int cap = i - ass;
  if(i == n-1){
    if(ass == cap+1) return capt[i];
    return inf;
  }
  if(ass == n/2) return suff_capt[i];
  if(cap < ass){
    return min((store[make_pair(i+1, ass+1)]=solve(i+1, ass+1))+assis[i], (store[make_pair(i+1, ass)]=solve(i+1, ass))+capt[i]);
  }
  return store[make_pair(i, ass)]=(solve(i+1, ass+1)+assis[i]);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> capt[i] >> assis[i];
  suff_capt[n-1] = capt[n-1];
  for(int i = n-2; i >= 0; i--)
    suff_capt[i] = suff_capt[i+1] + capt[i];
  cout << solve(0, 0) << endl;
}

