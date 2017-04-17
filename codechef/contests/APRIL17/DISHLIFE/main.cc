#include <bits/stdc++.h>

using namespace std;

int main(void){
  int t;
  int n, k, p, ing;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    unordered_set<int> st;
    unordered_multiset<int> mst;
    vector<int> island[n];
    for(int i=0; i<n; i++){
      vector<int> temp;
      scanf("%d", &p);
      for(int j=0; j<p; j++){
        scanf("%d", &ing);
        st.insert(ing);
        mst.insert(ing);
        temp.push_back(ing);
      }
      island[i] = temp;
    }
    bool sad = false, some = false, all = false;
    if(st.size() < k){
      printf("sad\n");
    }else{
      for(int i=0; i<n; i++){
        for(int ingredient: island[i]){
          auto it = mst.find(ingredient);
          mst.erase(it);
          if(mst.find(ingredient) == mst.end())
            st.erase(ingredient);
        }
        if(st.size() == k){
          some = true;
          break;
        }
        for(int ingredient: island[i]){
          st.insert(ingredient);
          mst.insert(ingredient);
        }
      }
      if(some){
        printf("some\n");
      }else{
        printf("all\n");
      }
    }
  }
}
