#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>

using namespace std;

map<char, set<int> > Adj;
map<char, int> indeg;

int main(void){
  int n;
  cin >> n;
  string a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int ind = 0;
      while(ind < min(a[i].length(), a[j].length())){
        if(a[i][ind] != a[j][ind]){
          Adj[a[i][ind]].insert(a[j][ind]);
          break;
        }
        if(ind == a[j].length()-1 && ind < a[i].length()-1){
          cout << "Impossible" << endl;
          return 0;
        }
        ind++;
      }
    }
  }
  set<char> discovered;
  for(auto it = Adj.begin(); it != Adj.end(); it++){
    discovered.insert(it->first);
    indeg[it->first];
    for(char x: it->second){ indeg[x] += 1; discovered.insert(x); }
  }
  stack<char> st;
  for(char x: discovered){
    if(indeg[x] == 0){
      st.push(x);
    }
  }
  vector<char> order;
  while(!st.empty()){
    char cur = st.top();
    order.push_back(cur);
    st.pop();
    for(char adj: Adj[cur]){
      indeg[adj] -= 1;
      if(indeg[adj] == 0) st.push(adj);
    }
  }
  //cerr << "order: ";
  //for(char x: order) cerr <<x << " ";
  //cerr << endl;
  if(order.size() != discovered.size()){
    cout<< "Impossible" << endl;
  }else{
    string letters = "abcdefghijklmnopqrstuvwxyz";
    set<char> letters_set(letters.begin(), letters.end());
    for(char x: order) letters_set.erase(x);
    for(char x: letters_set) order.push_back(x);
    for(char x: order) cout << x;
    cout << endl;
  }
}
