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

#define F(i, n) for(int i = 0; i < n; i += 1)
#define PRINT(a,n) for(int i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(int i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()

const int N = 500001;
const int LGN = 23;
int MaxTable[N][LGN+1], MinTable[N][LGN+1];

int main(void){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int a[n];
	arrinp(a,n);
	int LOGN = log2(n)+1;
	
	F(i,n){
		MinTable[i][0] = a[i];
		MaxTable[i][0] = a[i];
	}
	for(int j = 1; (1<<j) <= n; j += 1){
		for(int i = 0; (i+(1<<j)-1) < n; i += 1){
			MinTable[i][j] = min(MinTable[i][j-1], MinTable[i+(1<<(j-1))][j-1]);
			MaxTable[i][j] = max(MaxTable[i][j-1], MaxTable[i+(1<<(j-1))][j-1]);
		}
	}
	int x, y;
	F(i,q){
		cin >> x >> y;
		x--; y--;
		int LEN = log2(y-x+1);
		int MIN = min(MinTable[x][LEN], MinTable[y - (1<<LEN) + 1][LEN]);
		int MAX = max(MaxTable[x][LEN], MaxTable[y - (1<<LEN) + 1][LEN]);
//		cout << MIN << " " << MAX << endl;
		cout << MIN+MAX << endl;
	}
//	F(i,n){
//		F(j,LOGN){
//			cout << MinTable[i][j] << " ";
//		}
//		cout << endl;
//	}
}
