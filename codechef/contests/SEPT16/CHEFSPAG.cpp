/*input
3
4 1 2 3 4 0 1 2 3
1 1
2 1
2 2
1 2
4 1 2 3 4 0 1 2 3
1 1
3 1
3 3
1 3
3 1 2 3 4 0 1 2 3
1 2
5 1
4 4
*/

#include <bits/stdc++.h>

using namespace std;

#define inf INT_MAX
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define si set<ll>
#define mii map<ll, ll>
#define mci map<char, ll>
#define mic map<ll, char>
#define vit vi::iterator
#define sit si::iterator
#define psb push_back
#define ppb pop_back
#define mp make_pair
#define init(a, n) a.find(n) != a.end()
#define F(i,n) for (ll i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(ll i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(ll adj:g[i]) cout << adj <<" ";} cout << endl

#define ll long long

const ll mod = 1000000009;

class point{
public:
	ll x, y;
	point(){}
	point(ll a, ll b){
		x = a;
		y = b;
	}
};

point *Poly;

bool boundry(point p, point q, point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)){
        return true;
    }
    return false;
}

ll orient(point p, point q, point r){
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool iscross(point p1, point q1, point p2, point q2){
    ll ori1 = orient(p1, q1, p2);
    ll ori2 = orient(p1, q1, q2);
    ll ori3 = orient(p2, q2, p1);
    ll ori4 = orient(p2, q2, q1);
    if (ori1 != ori2 and ori3 != ori4) return true;
    if (ori1 == 0 && boundry(p1, p2, q1)) return true;
    if (ori2 == 0 && boundry(p1, q2, q1)) return true;
    if (ori3 == 0 && boundry(p2, p1, q2)) return true;
    if (ori4 == 0 && boundry(p2, q1, q2)) return true;
    return false;
}

bool inpoly(point p, point *Poly, ll n){
    if (n < 3)  return false;
    point outOfBound = {inf, p.y};
    ll res = 0, i = 0;
    for(int i = 0; i < n; i += 1){
    	if (p.x == Poly[i].x and p.y == Poly[i].y) return true;
    }
    do{
        ll next = (i+1)%n;
 		if (iscross(Poly[i], Poly[next], p, outOfBound)){
            if (boundry(Poly[i], p, Poly[next]) == 0) return true;
            res++;
        }
        i = next;
    }while (i != 0);
    return res&1; 
}



int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
		ll n, a, b, c, d, f0, f1, f2, f3, x, y;
		cin >> n;
		Poly = new point[n];
		cin >> a >> b >> c >> d >> f0 >> f1 >> f2 >> f3;
		for(ll i = 0; i < n; i += 1){
			cin >> x >> y;
			Poly[i] = point(x,y);
		}
		ll F[1000];
		F[0] = f0;
		F[1] = f1;
		F[2] = f2;
		F[3] = f3;
		for (ll i = 4; i < 1000; i += 1){
			F[i] = ((a*F[i-1])%mod + (b*F[i-2])%mod)%mod + ((c*F[i-3])%mod + (d*F[i-4])%mod)%mod;
			F[i] %= mod;
		}
		// cout << "DP table set" << endl;
		ll ans = 0;
		for (ll i = 0; i < 101; i += 1){
			for(ll j  = 0; j < 101; j += 1){
				if(inpoly(point(i,j), Poly, n) != 0){
					// cout << inpoly(point(i,j), Poly, n) << endl;
					cout << "i: " << i << " j: " << j << endl;
					ans += F[i+j];
					ans %= mod;
				}
			}
		}
		cout << ans << endl;
	}
	
}