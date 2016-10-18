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
#define ll long long
const int inf = INT_MAX;

int main(void){
	ios::sync_with_stdio(false);
	ll b, l, d;
	cin >> b >> l >> d;
	if(l < d and b < d){
		l++;
		b++;
	}else if(b < l){
		b++;
	}
	if (l < b and d < b){
		l++;
		d++;
	}else if(d < l){
		d++;
	}
	ll x = max(max(b, l), d);
	b -= x;
	l -= x;
	d -= x;
	cout << -(b+l+d) << endl;
	
}

