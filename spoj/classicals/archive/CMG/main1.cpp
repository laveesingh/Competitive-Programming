#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x;
  char q;
  scanf("%d", &t);
  int game=1;
  while(t--){
    printf("Case %d:\n", game++);
    scanf("%d", &n);
    map<int, int> _map;
    stack<int> _stack;
    while(n--){
      scanf("\n%c", &q);
      if(q == 'A'){
        scanf("%d", &x);
        _map[x]++;
        _stack.push(x);
      }else if(q == 'Q'){
        if(_stack.empty()){
          printf("Empty\n");
          continue;
        }
        printf("%d\n", (_map.rbegin()->first));
      }else{
        if(_stack.empty()){
          continue;
        }
        int cur = _stack.top();
        _stack.pop();
        _map[cur]--;
        if(_map[cur] == 0) _map.erase(cur);
      }
    }
  }
}
