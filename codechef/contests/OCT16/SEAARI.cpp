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

int main(void){
	ios::sync_with_stdio(false);
	ll N, K, D;
	cin >> N >> K >> D;
	ll a[N];
	arrinp(a, N);
	set<pii> store;
	F(i,N){
		store.insert({a[i], i});;
	}
	bool del[N];
	vi deletes;
	fill_n(del, N, false);
	while(D-- and !store.empty()){
		pii cur = *store.rbegin();
		del[cur.second] = true;
		deletes.push_back(cur.second);
		auto it = store.end();
		auto it2 = it;
		it2--;
		store.erase(it2,it);
	}
	int maxindex = N-1;
	vector<pii> vpi;
	while(K and !store.empty()){
		if(del[maxindex]) maxindex--;
		else{
			pii cur = *store.rbegin();
			if(maxindex == cur.second) { // do nothing
				auto it = store.end();
				auto it2 = it;
				it2--;
				store.erase(it2, it);
				maxindex--;
			}else{
				store.erase({a[cur.second], cur.second});
				store.erase({a[maxindex], maxindex});
				swap(a[maxindex], a[cur.second]);
				store.insert({a[cur.second], cur.second});
				vpi.push_back({cur.second, maxindex});
				maxindex--;
				K--;
			}
		}
	}
	ll sum = 0;
	ll num = 0;
	ll ft = inf;
	F(i,N){
		if (!del[i]){num += 1; ft = min(a[i], ft); sum += a[i];}
	}
	ll diff = (2*(sum - ft*num)) / (num*(num-1));
	cout << ft << " " << diff << endl;
	for (int i = 0; i < deletes.size(); i += 1){
		cout << 2 << " " << deletes[i]+1 << endl;
	}
	for(int i = 0; i < vpi.size(); i += 1){
		cout << 1 << " " << vpi[i].first+1 << " " << vpi[i].second+1 << endl;
	}
	cout << -1 << endl;
}

