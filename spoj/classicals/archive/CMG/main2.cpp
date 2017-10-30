#include <vector>
#include <cstdio>

using namespace std;

int main(void){
  int t, n, x;
  char q;
  scanf("%d", &t);
  for(int game=1; game<=t; game++){
    printf("Case %d:\n", game++);
    scanf("%d", &n);
    vector<int> stack;
    vector<int> maxyet;
    while(n--){
      scanf("\n%c", &q);
      if(q == 'A'){
        scanf("%d", &x);
        if(maxyet.empty()) maxyet.push_back(x);
        else maxyet.push_back((x > stack.back() ? x : stack.back()));
        stack.push_back(x);
      }else if(q == 'Q'){
        if(stack.empty()){
          printf("Empty\n");
          continue;
        }
        printf("%d\n", maxyet.back());
      }else{
        if(stack.empty()) continue;
        stack.pop_back();
        maxyet.pop_back();
      }
    }
  }
}

