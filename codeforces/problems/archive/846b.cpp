#include <bits/stdc++.h>

using namespace std;

int solve(int i, int m){
  int pts = 0, mx_pts = 0;
  for(int sub = 1; sub <= k; sub++){
    int ctime = psum[sub-1] * (n-i);
    if(ctime <= m){
      m -= ctime;
      pts = (n-i)*sub;
      if(sub == k)
        pts += n-i;
      pts = max(pts, mx_pts);
    }
  }
}
