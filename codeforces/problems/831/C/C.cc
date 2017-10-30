#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, k;
  cin >> n >> k;
  int a[n];
  int pa[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  pa[0] = a[0];
  for(int i = 1; i < n; i++) pa[i] = pa[i-1] + a[i];
  int b[k];
  set<int> bset;
  for(int i = 0; i < k; i++) {
    cin >> b[i];
    bset.insert(b[i]);
  }
  u must be knowing about ICPC and that you need a team of 3 members to participate in it. I've created a team that consists of 2 members (Me and Khusboo Gupta) i.e., we're searching for the third member. I wanted to know if you'll be interested. Let's not hold a thought of capabilities for now. Keeping no such factor in mind, tell me if you'll be interested.
  int bi = b[0];
  set<int> ans;
  for(int i = 0; i < n; i++){
    int x = bi - pa[i];
    set<int> bset2(bset.begin(), bset.end());
    for(int j = 0; j < n; j++){
      bset2.erase(pa[j] + x);
    }
    if(bset2.empty()) ans.insert(x);
  }
  cout << ans.size() << endl;
}
