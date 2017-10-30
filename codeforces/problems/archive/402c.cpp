#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n, p;
    cin >> n >> p;
    int last[n];
    fill_n(last, n, -1);
    //vector<int> adj[n];
    set<pair<int, int> > edges;
    for(int i = 0; i < n; i++){
      pair<int, int> edge1 = {i, (i+1)%n};
      pair<int, int> edge2 = {i, (i+2)%n};
      edges.insert(edge1);
      edges.insert(edge2);
      //adj[i].push_back((i+1)%n);
      //adj[i].push_back((i+2)%n);
      last[i] = (i+2)%n;
    }
    while(p > 0){
      //cerr << p << " edges to insert" << endl;
      for(int i = 0; i < n; i++){
        if(p <= 0) break;
        //cerr << "last of " << i << " is " << last[i] << endl;
        if(last[i] == (i+n-1)%n) continue;
        pair<int, int> edge1 = {i, (++last[i])%n};
        pair<int, int> edge2 = {last[i]%n, i};
        //cerr << "adding edge: " << edge1.first << " " << edge1.second << endl;
        if(edges.find(edge1) == edges.end() && edges.find(edge2) == edges.end()){
          --p;
          edges.insert(edge1);
          //adj[i].push_back(last[i]);
        }
      }
    }
    for(pair<int, int> edge: edges)
      cout << edge.first+1 << " " << edge.second+1 << endl;
  }
}

