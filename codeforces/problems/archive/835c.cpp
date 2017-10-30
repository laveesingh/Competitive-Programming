#include <bits/stdc++.h>

using namespace std;

const long long N = 101;
const long long T = 12;
long long sums[N][N][T];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, q, c, x, y, s;
  cin >> n >> q >> c;
  for(long long i = 0; i < n; i++){
    cin >> x >> y >> s;
    for(long long j = 0; j < T; j++)
      sums[x][y][j] += (s + j) % (c+1);
  }
  for(long long time = 0; time < T; time++)
    for(long long i = 1; i < N; i++)
      for(long long j = 1; j < N; j++)
        sums[i][j][time] += sums[i][j-1][time] + sums[i-1][j][time] - sums[i-1][j-1][time];
  long long t, xi1, yi1, xi2, yi2;

  for(long long i = 0; i < q; i++){
    cin >> t >> xi1 >> yi1 >> xi2 >> yi2;
    t %= (c+1);
    cout << sums[xi2][yi2][t] - sums[xi2][yi1-1][t] - sums[xi1-1][yi2][t] + sums[xi1-1][yi1-1][t] << endl;
  }
}

