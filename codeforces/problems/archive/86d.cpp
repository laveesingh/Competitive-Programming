#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;
typedef vector<int> vl;
typedef vector<vl> vvl;
typedef pair<pll, int> plll;
typedef map<int, int> mll;
typedef deque<int> dl;

#define F(i, n) for(int i = 0; i < n; i += 1)
#define PRINT(a,n) for(int i = 0; i < n; i += 1){ //cerr << a[i] << " ";} cerr<<endl;
#define arrinp(a,n) for(int i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()

const int SIZE = 200001;
int a[SIZE];
plll Q[SIZE];
ll ans = 0;
int cnt[1000001];
const int BLOCK = 500;

inline void add(int i){
	int x = cnt[a[i]];
	ans += a[i]*(2*x+1);
	cnt[a[i]]++;
}

inline void remove(int i){
	int x = cnt[a[i]];
	ans -= a[i]*(2*x-1);
	cnt[a[i]]--;
}

bool cmp(plll x, plll y){
	if(x.first.first/BLOCK == y.first.first/BLOCK){
		return x.first.second < y.first.second;
	}
	return x.first.first < y.first.first;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	// scanf("%d %d",&n, &t);
//	int a[n];
	// a = new int[n];
	arrinp(a,n);
//	plll Q[t];
	// Q = new plll[t];
	int x, y;
	F(i,t){
		cin >> x >> y;
		// scanf("%d %d", &x, &y);
		x--;
		y--;
		Q[i] = {{x,y}, i};
	}
	sort(Q, Q+t, cmp);
	ll results[t];
	int curL = 0, curR = 0;
	F(i,t){
		int l = Q[i].first.first;
		int r = Q[i].first.second;
		//cerr << "Performing: l " << l << " r " << r << " ";
		//cerr << "count=" << ans << " ";
		while(curR <= r){
			add(curR);
			curR++;
		}
		//cerr << "count=" << ans << " ";
		while (curR > r+1){
			remove(curR-1);
			curR--;
		}//cerr << "count=" << ans << " ";

		while(curL <= l){
			remove(curL);
			curL++;
		}//cerr << "count=" << ans << " ";

		while(curL > l){
			add(curL-1);
			curL--;
		}//cerr << "count=" << ans << " ";

		//cerr << "Ans: " << ans << endl;
		results[Q[i].second] = ans;
	}
	F(i,t){
		cout << results[i] << endl;
		// printf("%lld\n", results[i]);
	}
}




