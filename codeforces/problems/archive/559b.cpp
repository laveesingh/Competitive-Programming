#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 1;
char a[N], b[N];

bool solve(int i1, int j1, int i2, int j2){
  bool equal = true;
  for(int i = 0; i <= (j1-i1); i++){
    if(a[i+i1] != b[i+i2]) equal = false;
  }
  if(equal){
    return true;
  }
  if((j1-i1)%2 == 0) {
    return false;
  }
  int m1 = (i1 + j1)/2;
  int m2 = (i2 + j2)/2;
  if((solve(i1, m1, i2, m2) && solve(m1+1, j1, m2+1, j2)) || 
      (solve(i1, m1, m2+1, j2) && solve(m1+1, j1, i2, m2))){
    return true;
  }
  return false;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  //string a, b;
  //cin >> a >> b;
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a);
  cout << (solve(0, n-1, 0, n-1) ? "YES" : "NO") << endl;
}

