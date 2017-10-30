#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  long long psum[n];
  fill_n(psum, n, 0);
  for(long long i = 0; i < n; i++){
    cin >> a[i];
    if(i == 0)
      psum[i] = a[i];
    else
      psum[i] = psum[i-1] + a[i];
  }
  long long total = psum[n-1];
  vector<long long> inds, inds2;
  if(total % 3){
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for(long long i = 0; i < n; i++){
    if(psum[i] == total/3) inds.push_back(i);
    if(psum[i] == (2*total)/3) if(i != 0 && i != n-1) inds2.push_back(i);
  }
  for(long long index1: inds){
    //cerr << "For index: " << index1 << " ";
    long long vindex = upper_bound(inds2.begin(), inds2.end(), index1) - inds2.begin();
    //cerr << "found " << inds2[vindex] << endl;
    ans += inds2.size() - vindex;
  }
  cout << ans << endl;
}

