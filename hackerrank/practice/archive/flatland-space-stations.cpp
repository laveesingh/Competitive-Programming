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

const int inf = INT_MAX;

int main(void){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int station[n];
	memset(station, 0, sizeof(int)*n);
	int x;
	F(i,m){
		cin >> x;
		station[x] = 1;
	}
	int dp[n], revdp[n], dist[n];
	if(station[0]) dp[0] = 0;
	else dp[0] = inf;
	for(int i = 1; i < n; i += 1){
		if (statoin[i]) dp[i] = 0;
		else dp[i] = dp[i-1]+1;
	}
	if(station[n-1])revdp[n-1]=0;
	else revdp[n-1] = inf;
	for(int i = n-2; i >= 0; i -= 1){
		if(station[i]) revdp[i] = 0;
		else dp[i] = revdp[i+1]+1;
	}
	F(i,n){
		dist[i] = min(dp[i], revdp[i]);
	}
	cout << *max_element(dist, dist+n) << endl;
}
