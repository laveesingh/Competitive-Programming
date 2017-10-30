#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
string a;

bool match(long long st){
  string pat = a.substr(0, st+1);
  string str = a.substr(1, a.length()-2);
  long long n = str.length(),
      m = pat.length();
  if(n < m) return false;
  long long lps[n];
  lps[0] = 0;
  long long i = 1, len = 0;
  while(i < m){
    if(pat[i] == pat[len])
      lps[i++] = ++len;
    else{
      if(len != 0)
        len = lps[len-1];
      else
        lps[i++] = 0;
    }
  }
  i = 0;
  long long j = 0;
  while(i < n){
    //cerr << "kmp i: " << i << " j: " << j << endl;
    //cerr << "str: " << str << " pat: " << pat << endl;
    if(str[i] == pat[j])
      i++, j++;
    if(j == m){
      //cerr << "Found " << st << " : " << pat << " at " << j+1 << endl;
      return true;
    }
    else if(i < n and str[i] != pat[j]){
      if(j != 0)
        j = lps[j-1];
      else
        i++;
    }
  }
  return false;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a;
  long long n = a.length();
  long long mul1 = 1,
      fhash = 0,
      shash = 0;
  long long p = 37;
  vector< pair<long long, long long> > commons;
  for(long long len = 1; len < n; len++){
    long long x = len - 1,
        y = n - len;
    //cerr << "x: " << x << " y: " << y << endl;
    fhash = (fhash + (a[x]-'a'+1)*mul1 % mod ) % mod;
    mul1 = (mul1 * p) % mod;
    shash = (shash * p) % mod;
    shash = (shash + (a[y]-'a'+1)) % mod;
    //cerr << "fhash: " << fhash << " shash: " << shash << endl;
    if(fhash == shash){
      commons.push_back({x, y});
      //cerr << x << " is lucky" << endl;
    }
  }
  //cerr << "out of for loop" << endl;
  bool legend = false;
  if(commons.empty()) legend = true;
  if(legend){
    cout << "Just a legend" << endl;
    return 0;
  }
  if(!match(commons[0].first)) legend = true;
  if(legend){
    cout << "Just a legend" << endl;
    return 0;
  }
  long long lo = 0, hi = commons.size() - 1, mid = -1;
  //cerr << "going to while loop" << endl;
  while(lo <= hi){
    //cerr << lo << " " << hi << endl;
    if(mid == (lo + hi)/2) break;
    mid = (lo + hi)/2;
    long long x = commons[mid].first,
        y = commons[mid].second;
    if(match(x))
      lo = mid;
    else
      hi = mid;
  }
  if(lo > hi)
    swap(lo, hi);
  pair<long long, long long> ans;
  if(match(commons[hi].first))
    ans = commons[hi];
  else
    ans = commons[lo];
  for(long long i = 0; i <= ans.first; i++) cout << a[i];
  cout << endl;
}
