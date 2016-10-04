#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<pii, int> piii;
typedef map<int, int> mii;
typedef deque<int> di;
typedef set<int> si;


typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<pll, ll> plll;
typedef map<ll, ll> mll;
typedef deque<ll> dl;
typedef set<ll> sl;

#define F(i, n) for(ll i = 0; i < n; i += 1)
#define PRINT(a,n) for(ll i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(ll i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()
#define front(a) *(a.begin())
#define back(a) *(a.rbegin())
const int inf = INT_MAX;
multiset<int> Map;
int Min = inf, Max = -inf;
const int BLOCK = 1000;
int a[500001];
inline void add(int i){
	Min = min(Min, a[i]);
	Max = max(Max, a[i]);
	Map.insert(a[i]);
}

inline void remove(int i){
	auto it = Map.find(a[i]);
	auto it2 = it;
	++it2;
	Map.erase(it, it2);
	Min = front(Map);
	Max = back(Map);
}

bool cmp(piii x, piii y){
	if (x.first.first/BLOCK == y.first.first/BLOCK){
		return x.first.second < y.first.second;
	}
	return x.first.first < y.first.first;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	arrinp(a,n);
	piii Q[q];
	int tempx, tempy;
	F(i,q){
		cin >> tempx >> tempy;
		tempx--; tempy--;
		Q[i] = {{tempx, tempy}, i};
	}
	sort(Q, Q+q, cmp);
	int Ans[q];
	int L = 0, R = 0;
	F(i,q){
		#ifdef DEBUG
			cerr << "Min:" << Min << ":Max:" << Max;
		#endif
		int l = Q[i].first.first;
		int r = Q[i].first.second;
		#ifdef DEBUG
			cerr << ":l:" << l << ":r:" << r <<":L:"<< L << ":R:" << R ;
		#endif
		while (R <= r){
			#ifdef DEBUG
				cerr << ":Adding: " << R;
			#endif
			add(R);
			R++;
		}
		while (L < l){
			#ifdef DEBUG
				cerr << ":Removing: " << L;
			#endif
			remove(L);
			L++;
		}
		while (R > r+1){
			#ifdef DEBUG
				cerr << ":Removing:" << R-1;
			#endif
			
			remove(R-1);
			R--;
		}
		while(L > l){
			#ifdef DEBUG
				cerr << ":Adding:"<<L-1;
			#endif
			add(L-1);
			L--;
		}
		Ans[Q[i].second] = Min+Max;
		#ifdef DEBUG
			cerr << ":L:"<<L<<":R:"<<R<<":MIN:"<<Min<<":Max:"<<Max<<endl;
		#endif
	}
	F(i,q){
		cout << Ans[i] << endl;
	}
}

