#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int zfix[n];
  fill_n(zfix, n, 0);
  if(a[n-1] == 0) zfix[n-1] = 1;
  for(int i = n-2; i >= 0; i--){
    if(a[i] == 0) zfix[i] = zfix[i+1] + 1;
    else zfix[i] = zfix[i+1];
  }


}
