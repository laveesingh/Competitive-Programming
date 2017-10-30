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
#define front(a) *(a.begin())
#define back(a) *(a.rbegin())

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	arrinp(a, n);
	sort(a, a+n);
	int ans = -1;
	int i = n-3;
	while(i >= 0){
		if(a[i]+a[i+1] > a[i+2]){
			ans = i;
			break;
		}
		i--;
	}
	if(ans == -1){
		cout << ans << endl;
	}else{
		cout << a[i] << " " << a[i+1] << " " << a[i+2] << endl;
	}
}

