#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;
const long long N = 1e5 + 1;

long long a[N], b[N], c[N], pa[N], pc[N];

inline long long ps_a(long long i){
    i--;
    if(i < 0) return 0;
    return pa[i];
}

inline long long ps_c(long long i){
    i--;
    if(i < 0) return 0;
    return pc[i];
}

int main(void){
  ios::sync_with_stdio(false);
  long long p, q, r, t;
  cin >> t;
  while(t--){
    cin >> p >> q >> r;
    for(long long i = 0; i < p; i++)
        cin >> a[i];
    for(long long i = 0; i < q; i++)
        cin >> b[i];
    for(long long i = 0; i < r; i++)
        cin >> c[i];
    sort(a, a+p);
    sort(b, b+q);
    sort(c, c+r);
    // cerr << "sorted all the arrays" << endl;
    pa[0] = a[0];
    for(long long i = 1; i < p; i++)
        pa[i] = (pa[i-1] + a[i]) % MOD;
    pc[0] = c[0];
    for(long long i = 1; i < r; i++)
        pc[i] = (pc[i-1] + c[i]) % MOD;
    //cerr << "prefix sums go as follows" << endl;
    // for(long long i = 0; i < p; i++)
    //     cerr << pa[i] << " ";
    // cerr << endl;
    // for(long long i = 0; i < r; i++)
    //     cerr << pc[i] << " ";
    // cerr << endl;
    long long ans = 0;
    for(long long i = 0; i < q; i += 1){
        long long elem = b[i];
        long long ix = upper_bound(a, a+p, elem) - a;
        long long iy = upper_bound(c, c+r, elem) - c;
        // cerr << "ix: " << ix << " iy: " << iy << endl;
        // cerr << ps_a(ix) << ", " << ps_c(iy) << endl;
        ans += (ps_a(ix) + (ix*elem)%MOD) * (ps_c(iy) + (iy*elem)%MOD) % MOD;
        ans = ans % MOD;
    }
    cout << ans << endl;
  }
}
