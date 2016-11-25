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
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int Range[n];
		F(i,n){
			Range[i] = i+1;
		}
		int avail[n+1];
		memset(avail, 0, sizeof(int)*(n+1));
		int ans[n];
		bool flag = false;
		F(i,n){
			int choice1 = Range[i] - k;
			int choice2 = Range[i] + k;
			if(choice1 >= 1 and avail[choice1] == 0){
				ans[i] = choice1;
				avail[choice1] = 1;
			}else if(choice2 <= n and avail[choice2] == 0){
				ans[i] = choice2;
				avail[choice2] = 1;
			}else{
				flag = true;
				break;
			}
		}
		if(flag == true){
			cout << "-1" << endl;
		}else{
			F(i,n){
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
}
