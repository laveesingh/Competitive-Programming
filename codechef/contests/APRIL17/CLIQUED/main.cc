#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const long long inf = 1e17+7;
const long long N = 1e5 + 1;
long long t, n, k, x, m, s, tempx, tempy, tempz;
map<pair<long long, long long>, long long> dist;
vector<long long> adj[N];

inline bool cliqued(long long node){
  return node < k;
}

inline long long distance(long long p, long long q){
  if(cliqued(p) and cliqued(q)) return x;
  return dist[make_pair(p, q)];
}

int main(void){
  cin >> t;
  while(t--){
    cin >> n >> k >> x >> m >> s;
    s--;
    dist.clear();
    for(long long i=0; i<n; i++){
      adj[i].clear();
    }
    //for(long long i=0; i<k; i++)
      //for(long long j=0; j<k; j++){
        //dist[make_pair(i, j)] = (i==j ? 0 : x);
        //adj[i].push_back(j);
      //}
    for(long long i=0; i<m; i++){
      cin >> tempx >> tempy >> tempz;
      tempx--, tempy--;
      dist[make_pair(tempx, tempy)] = dist[make_pair(tempy, tempx)] = tempz;
      adj[tempx].push_back(tempy);
      adj[tempy].push_back(tempx);
    }
    set<pair<long long, long long> > st;
    long long sp[n];
    fill_n(sp, n, inf);
    sp[s] = 0;
    st.insert({sp[s], s});
    while(!st.empty()){
      auto cur = *st.begin();
      //cerr << "choosing: " << cur.second << ": " << cur.first << endl;
      st.erase(st.begin());
      for(long long Adj: adj[cur.second]){
        //if(cur.first+dist[make_pair(cur.second, Adj)] < sp[Adj]){
        if(cur.first + distance(cur.second, Adj) < sp[Adj]){
          st.erase({sp[Adj], Adj});
          //sp[Adj] =  cur.first+dist[make_pair(cur.second, Adj)];
          sp[Adj] = cur.first + distance(cur.second, Adj);
          st.insert({sp[Adj], Adj});
        }
      }
    }
    for(long long i=0; i<n; i++)
      cout << sp[i] << " ";
    cout << endl;
  }
}