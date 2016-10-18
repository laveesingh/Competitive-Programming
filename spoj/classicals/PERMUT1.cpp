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

map<pii, int> store;

int perm(int n, int k){
	if(store[make_pair(n, k)]) return store[make_pair(n, k)];
	if (k < 0) return 0;
	if (k == 0) return 1;
	if (n == 1) return k == 0;
	if (n == 2) return (k == 0 or  k == 1);
	int x = 0;
	for(int i = 0; i < n; i += 1){
		x += perm(n-1, k-i);
	}
	return store[make_pair(n, k)] = x;
}
		


int main(void){
	ios::sync_with_stdio(false);
	int d;
	cin >> d;
	while(d--){
		int n, k;
		cin >> n >> k;
		cout << perm(n, k) << endl;
	}
}

