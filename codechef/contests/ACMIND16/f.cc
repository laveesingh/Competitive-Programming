#include <iostream>
#include <vector>


using namespace std;

const int N = 101;

vector<int> Adj[N];

int main(void){
  int t, n, m, d, D;
  cin >> t;
  while(t--){
    cin >> n >> m >> d >> D;
    for(int i = 0; i < N; i++) Adj[i].clear();
    int total_edges = 0;
    int cur = 0;
    while(total_edges < m){
      int x;
      if(Adj[cur].empty()) x = cur;
      else
        x = (Adj[cur].back() + 1)%n;
      Adj[cur].push_back(x);
      //Adj[x].push_back(cur);
      cur = (cur + 1) % n;
      total_edges += 1;
    }
    int cool = true;
    for(int i = 0; i < n; i++){
      if(Adj[i].size() < d){
        cool = false;
        break;
      }
      if(Adj[i].size() > D){
        cool = false;
        break;
      }
    }
    if(!cool){
      cout <<  -1 << endl;
    }else{
      for(int i = 0; i < n; i++){
        for(int adj: Adj[i]){
          cout << i+1 << " " << adj+1 << endl;
        }
      }
    }
  }
}
