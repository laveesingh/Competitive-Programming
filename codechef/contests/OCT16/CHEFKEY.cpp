#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<pii, int> piii;
typedef map<int, int> mii;
typedef deque<int> di;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<pll, ll> plll;
typedef map<ll, ll> mll;
typedef deque<ll> dl;

#define F(i, n) for(ll i = 0; i < n; i += 1)
#define PRINT(a,n) for(ll i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(ll i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()
#define Front(a) *(a.begin())
#define Back(a) *(a.rbegin())
#define Index(a, x) a.find(x) - a.begin()

const int inf = INT_MAX;

inline void solve(int n, int m, int c, int& ans){
	int d = 1;
	while(d <= sqrt(c)){
		if(c % d == 0){
			int x = c/d;
			int y = d;
			if(x <= n and y <= m) ans += 1;
			if (x != y and x <= m and y <= n) ans += 1;
		}
		d += 1;
	}
	//return ans;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int c;
		cin >> c;
		int ans = 0;
		solve(n, m, c, ans);
		cout << ans << endl;
	}
}

