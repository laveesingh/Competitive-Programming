/*input
7 7
3 1
2 1
7 6
6 3
5 3
4 3
7 2 3
7 1 1
2 3 5
3 6 2
4 2 4
5 3 10
6 1 20
3
5
6
7
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define si set<ll>
#define mii map<ll, ll>
#define mci map<char, ll>
#define mic map<ll, char>
#define vit vi::iterator
#define sit si::iterator
#define psb push_back
#define ppb pop_back
#define mp make_pair
#define init(a, n) a.find(n) != a.end()
#define F(i,n) for (ll i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define prll(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define prllgraph(g,n) for(ll i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(ll adj:g[i]) cout << adj <<" ";} cout << endl
const ll inf = 1000000000000000000;
 
 
int main(void){
	ios::sync_with_stdio(false);
	ll n, m, q, x, y, v, k, w;
 
 
	// Input is taken here
	cin >> n >> m;
	vi *G = new vi[n+1];
	ll *parent = new ll[n+1];
	memset(parent, 0, sizeof(ll)*(n+1));
	ll *level = new ll[n+1];
	memset(level, 0, sizeof(ll)*(n+1));
	ll *dist = new ll[n+1];
	fill_n(dist, n+1, inf);
	for(ll i = 0; i < n-1; i += 1){
		cin >> x >> y;
		G[y].psb(x); // storing the reverse node here
		parent[x] = y;
	}
	vector<pii> *ticket = new vector<pii>[n+1];
	for(ll i = 0; i < m; i += 1){
		cin >> v >> k >> w;
		ticket[v].psb({k,w}); // pair of {range, weight}
	}
 
	// Solution starts here
	stack<ll> Queue;
	ll *store  = new ll[100001]; // store the actual distances in current dfs tree
	vi sqT; // Sqrt-decomposed table of at most length 315
	ll spoll = 315, store_index = -1;
	level[1] = 1;
	dist[1] = 0;
	Queue.push(1);
	while(!Queue.empty()){
		ll cur = Queue.top(); Queue.pop();
		// cerr << "queue: " << cur << endl;
		bool flag = false; // to check if current dfs tree ends here
		for(ll child: G[cur]){
			// if no child, flag remains false and dfs tree ends
			flag = true;
			Queue.push(child);
			level[child] = level[cur] + 1;
		}
		if(cur == 1){
			dist[cur] = 0;
			store[++store_index] = 0;
			continue; // not sure if there's something else to do with first node
		}
		for(pii cticket: ticket[cur]){
			ll curk = cticket.first;
			ll w = cticket.second;
			if(curk > store_index+1) curk = store_index+1;
			// ll curkmod = (min(curk, store_index+1))%spoll; // how many elements we have to check manually after sqrt segments
			ll curkmod = (store_index+1)%spoll;
			curkmod = min(curk, curkmod);
			ll tsind = store_index; // temporary store index
			ll min1 = inf;
			curk -= curkmod;
			while(curkmod-- > 0 and tsind >= 0){
				min1 = min(min1, store[tsind--]);
			}
			ll sqtind = sqT.size()-1; // going to check in sqrt decomposed table
			ll min2 = inf;
			while (curk >= spoll and tsind >= spoll and sqtind >= 0){
				curk -= spoll;
				tsind -= spoll;
				min2 = min(min2, sqT[sqtind--]);
			}
			ll min3 = inf;
			while(curk-- > 0 and tsind >= 0){
				min3 = min(min3, store[tsind--]);
			}
			// cerr << "dist["<<cur<<"]: " << dist[cur] << " ==> ";
			if(min2 < min1) min1 = min2;
			if (min3 < min1) min1 = min3;
			if(min1+w < dist[cur]) dist[cur] = min1+w;
			// cerr << "dist["<<cur<<"]: " << dist[cur] << endl;
			// store[++store_index] = dist[cur];
			store[store_index+1] = dist[cur];
			
		}
		++store_index;
		if((store_index+1)%spoll == 0){
			sqT.psb(*min_element(store+(store_index+1-spoll), store+(store_index+1)));
		}
		if(flag == false and !Queue.empty()){
			ll last = Queue.top();
			ll cparent = parent[last];
			ll cplevel = level[cparent];
			store_index = cplevel - 1;
			while(sqT.size() > (store_index+1)/spoll){
				sqT.ppb();
			}
		}
	}
	cin >> q;
	// cerr << "q; " << q << endl;
	for (ll i = 0; i < q; i += 1){
		ll h;
		cin >> h;
		// cerr << "i: " << i << "h: " << h << endl;
		cout << dist[h] << endl;
	}
} 