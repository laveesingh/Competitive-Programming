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

inline void increase(string& a, int ind){
	for(int i = ind+1; i < a.length(); i += 1) a[i] = '0';
	while (ind >= 0){
		if(a[ind] == '.') ind--;
		if (a[ind] < '9'){
			a[ind] += 1;
			break;
		}else{
			a[ind] = '0';
		}
		ind--;
	}
	if(a[0] == '0') a =  "1"+a;
	
}

int main(void){
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	string a;
	cin >> a;
	int IND = a.find('.'); 
	int Flen = n-IND-1;
	int dp[Flen];
	dp[Flen-1] = inf;
	for(int i = Flen-2; i >= 0; i -= 1){
		if (a[i+IND+2] < '4') dp[i] = inf;
		else if (a[i+IND+2] >= '5') dp[i] = 1;
		else dp[i] = (dp[i+1]==inf ? inf : dp[i+1]+1);
	}
	int Rindex = -1;
//	F(i,Flen) cout << dp[i] << " ";
//	cout << endl;
	for(int i = 0;i < Flen; i += 1){
		if(dp[i] <= t){
			Rindex = i;
			break;
		}
	
	}
	int Dig = (a[IND+1] >= '5' ? 1 : ((dp[0]==inf or a[IND+1] < '4')? inf: dp[0]+1));

	if(Dig <= t){
		increase(a, IND);
//	cout << "first" << endl;
	}
	else if(Rindex > -1)
		increase(a, Rindex+IND+1);
	n = a.length();
	IND = a.find('.');
	int j = IND;
	while(j < n){
		if (a[j] != '0') IND = j;
		j++;
	}
	string ans = a.substr(0, (a[IND] == '.' ? IND : IND+1));
	cout << ans << endl;
	
}

