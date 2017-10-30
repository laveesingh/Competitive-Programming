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

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	arrinp(a, n);
	int ans = INT_MAX;
	F(i,n){
		for(int j = i+1; j < n; j += 1){
			if(a[i] == a[j]){
				ans = min(ans, (int)(j-i));
			}
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;
}

