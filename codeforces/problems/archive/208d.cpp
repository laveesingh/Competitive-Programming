#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long p[n];
  for(long long i = 0; i < n; i++) cin >> p[i];
  long long a, b, c, d, e;
  long long ta = 0, tb = 0, tc = 0, td = 0, te = 0;
  cin >> a >> b >> c >> d >> e;
  long long r = 0;
  for(long long i = 0; i < n; i++){
    r += p[i];
    te = te + r / e, r %= e;
    td = td + r / d, r %= d;
    tc = tc + r / c, r %= c;
    tb = tb + r / b, r %= b;
    ta = ta + r / a, r %= a;
  }
  cout << ta << " " << tb << " " << tc << " " << td << " " << te << endl;
  cout << r << endl;
}

