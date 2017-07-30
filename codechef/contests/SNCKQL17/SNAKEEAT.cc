#include <bits/stdc++.h>

using namespace std;

int main(void){
  long long t, n, q, k;
  cin >> t;
  while(t--){
    cin >> n >> q;
    long long a[n];
    map<long long, long long> ans;
    for(long long i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a+n);
    for(long long i = 0; i < q; i++){
      cin >> k;
      if(ans[k]){
        cout << ans[k] << endl;
        continue;
      }
      long long lb = lower_bound(a, a+n, k) - a;
      long long start = 0;
      long long end = lb-1;
      long long cnt = n - lb;
      while (start <= end){
        long long req = k - a[end];
        start += req;
        if(start <= end)
          cnt += 1;
        else
          break;
        end--;
      }
      ans[k] = cnt;
      cout << cnt << endl;
    }
  }
}
