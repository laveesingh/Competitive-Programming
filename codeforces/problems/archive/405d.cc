#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main(void){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  set<int> aset(a, a+n);
  int s = 1e6, sym = 0;
  set<int> bset;
  for(int x: aset){
    int comp = s - x + 1;
    if(aset.find(comp) != aset.end()) sym++;
    else bset.insert(comp);
  }
  //cerr << "sym: " << sym << endl;
  for(int i = 1; i <= s; i++){
    if(sym == 0) break;
    if(aset.find(i) == aset.end() and aset.find(s-i+1) == aset.end()){
      bset.insert(i), sym--;
      bset.insert(s-i+1), sym--;
    }
  }
  printf("%d\n", bset.size());
  for(int y: bset)
    printf("%d ", y);
  printf("\n");
}
