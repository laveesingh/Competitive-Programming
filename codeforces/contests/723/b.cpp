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
	string a;
	cin >> a;
	bool in = false;
	int curlen = 0, maxlen = 0, inword = 0;
	F(i,n){
		if (in){
			char cur = a[i];
			if(isalpha(cur)){
				curlen++;
			}else if(a[i] == '_'){
				if(curlen > 0){
					curlen = 0;
					inword++;
				}
			}else if(a[i] == ')'){
				in = false;
				if (curlen > 0){
					inword++;
					curlen = 0;
				}
			}
		}else{
			char cur = a[i];
			if (a[i] == '('){
				in = true;
				if(curlen > 0){
					maxlen = max(maxlen, curlen);
					curlen = 0;
				}
			}else if(isalpha(cur)){
				curlen++;
				if(i == n-1) maxlen = max(maxlen, curlen);
			}else if(a[i] == '_'){
				if(curlen > 0){
					maxlen = max(maxlen, curlen);
					curlen = 0;
				}
			}
		}
	}
	cout << maxlen << " " << inword << endl;
}

