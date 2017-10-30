#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for(int i =0 ; i < n; i += 1) cin >> a[i];
  int freq[n];
  memset(freq, 0, n);
  bool inc = false, dec = false, con = false, wrong=false;
  for(int i = 1; i < n; i += 1){
    if(a[i] == a[i-1]){
      if(dec) wrong=true;
      con = true;
    }else if(a[i] > a[i-1]){
      if(dec or con) wrong=true;
      inc = true;
    }else{
      dec = true;
    }
  }
  if(wrong) cout << "NO" << endl;
  else cout << "YES" << endl;
}


