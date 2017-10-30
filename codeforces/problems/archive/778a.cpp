#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 1;
string w, p;
int a[N];
bool del[N];
int n;

bool make(int mid){
  for(int i = 0; i < n; i++) del[i] = false;
  for(int i = 0; i < mid; i++) del[a[i]] = true;
  for(int i = mid; i < n; i++) del[a[i]] = false;
  int ind = 0;
  for(int i = 0; i < n; i++){
    if(del[i]) continue;
    if(w[i] == p[ind]) ind++;
    else{
    }
    if(ind == p.length()) return true;
  }
  return false;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> w >> p;
  n = w.length();
  for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
  int lo = 0, hi = n, mid = -1;
  while(lo <= hi){
    if(mid == (lo + hi)/2) break;
    mid = (lo + hi)/2;
    if(make(mid)){
      lo = mid;
    }else{
      hi = mid;
    }
  }
  if(lo > hi) swap(lo, hi);
  if(make(hi)) cout << hi << endl;
  else cout << lo << endl;
}

