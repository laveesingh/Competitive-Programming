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
const int SIZE = 200001;
int n, m, k;
int colors[SIZE];
vvi graph(SIZE);
int visited[SIZE];
vvi components;

void dfs(int i, vi& component){
	for(int adj: graph[i]){
		if (!visited[adj]){
			visited[adj] = 1;
			component.push_back(adj);
//			cout << "rec Pushing " << adj << " to component" << endl;
			dfs(adj, component);
		}
	}
}
map<int, int> freq;
int maxcost(vi& a){
	freq.clear();
	int maxoc = 0, maxelem = 0;
	for(int x: a){
		freq[colors[x]]++;
		if(freq[colors[x]] > maxoc){
			maxoc = freq[colors[x]];
			maxelem = x;
		}
	}
	return a.size() - maxoc;
}

int main(void){
	ios::sync_with_stdio(false);
	int x, y;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> colors[i];
	}
	for(int i = 0; i < m; i += 1){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for(int i = 1; i <= n; i += 1){
		//PRINT(visited, 7);
		if(!visited[i]){
			visited[i] = 1;
			vi component;
			component.push_back(i);
			//cout << "pushing " << i << "to component" << endl;
			dfs(i,component);
			components.push_back(component);
		}
	}
//	cout << "Size of component: " << components.size() << endl;
//	for(vi& comp: components){
//		for(int s: comp){
//			cout << s << " ";
//		}
//		cout << endl;
//	}
	int ans = 0;
	for(vi& component: components){
		ans += maxcost(component);
	}
	cout << ans << endl;
}

