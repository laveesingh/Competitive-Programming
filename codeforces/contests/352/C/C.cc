#include <bits/stdc++.h>

using namespace std;

const long long N = 2e3 + 1;

long long n;
double a[2*N];
double store[2*N][2*N];
double minimum(double x, double b){
  if(abs(x) < abs(b)) return x;
  return b;
}

double solve(long long i, long long x){
  if(store[i][x] != -1.0) return store[i][x];
  if(i == 2*n-1){
    if(x == n) return ceil(a[i]) - a[i];
    if(x == n-1) return floor(a[i]) - a[i];
    return 1e9;
  }
  double f = ceil(a[i]) - a[i];
  double s = floor(a[i]) - a[i];
  if (x == n)
    return (store[i+1][x] = solve(i+1, x)) + f;
  if (i-x == n)
    return (store[i+1][x+1] = solve(i+1, x+1)) + s;
  return minimum(
        (store[i+1][x+1] = solve(i+1, x+1)) + s, 
        (store[i+1][x] = solve(i+1, x)) + f
      );
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(long long i = 0; i < 2*n; i++) cin >> a[i];
  for(long long i = 0; i < 2*n; i++){
    for(long long j = 0; j < 2*n; j++) store[i][j] = -1.0;
  }
  double ans = solve(0, 0);
  printf("%0.3lf", abs(ans));
}
