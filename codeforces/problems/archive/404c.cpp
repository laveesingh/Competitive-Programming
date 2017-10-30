#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int dist[n];
  for(int i = 0; i < n; i++) cin >> dist[i];
  map<int, vector<int> > nodes;
  vector<int> Adj[n];
  int src = 0, srcnt = 0;
  for(int i = 0; i < n; i++){
    if(dist[i] == 0) src = i, srcnt++;
    nodes[dist[i]].push_back(i);
  }
  bool possible = srcnt == 1;
  int edgecnt = 0;
  set<pair<int, int> > edges;
  for(int level = 1; level <= n-1; level++){
    vector<int> pars = vector<int>(nodes[level-1].begin(), nodes[level-1].end());
    vector<int> children = vector<int>(nodes[level].begin(), nodes[level].end());
    if(children.empty()) break;
    if(children.size() > pars.size()*k){ possible = false; break; }
    //cerr << "children for level: " << level << endl;
    //for(int child: children) cerr << child << " ";
    //cerr << endl;
    while(!pars.empty() && !children.empty()){
      int cur_par = pars.back();
      pars.pop_back();
      while(!children.empty()){
        if(Adj[cur_par].size() == k) break;
        Adj[cur_par].push_back(children.back());
        Adj[children.back()].push_back(cur_par);
        //cerr << "pushing " << cur_par << " to " << children.back() << endl;
        //cerr << "pushing " << children.back() << " to " << cur_par << endl;
        edges.insert({ cur_par, children.back() });
        edgecnt++;
        children.pop_back();
      }
    }
  }
  if(edgecnt < n-1 || !possible) cout << -1 << endl;
  else{
    cout << edges.size() << endl;
    for(pair<int, int> edge: edges) cout << edge.first+1 << " " << edge.second+1 << endl;
  }
}

