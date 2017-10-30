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

ll solve(ll a[], int lo, int hi, ll ans, ll sum){
	if(hi-lo+1 < 2) return ans;
	ll leftsum = 0ll;
	for(int i = lo; i <= hi; i += 1){	
		leftsum += a[i];
		if(leftsum == sum-leftsum){
			return max(solve(a, lo, i, ans+1, leftsum), solve(a, i+1, hi, ans+1, leftsum)); 
		}
		if(2*leftsum > sum) return ans;
	}
	return ans;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[n];
		arrinp(a, n);
		cout << solve(a, 0, n-1, 0, accumulate(a, a+n, 0ll)) << endl;
	}
}

