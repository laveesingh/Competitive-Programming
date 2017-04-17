#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int t;
  string ing;
  cin >> t;
  while(t--){
    set<string> dish;
    for(int i=0; i<4; i++)
      cin >> ing, dish.insert(ing);
    int sim = 0;
    for(int i=0; i<4; i++){
      cin >> ing;
      if(dish.find(ing) != dish.end())
        sim++;
    }
    cout << (sim>=2 ? "similar" : "dissimilar") << endl;
  }
}
