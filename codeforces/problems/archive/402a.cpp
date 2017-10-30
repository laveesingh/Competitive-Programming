#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int boxes = 0;
  while(a > 0){
    //cerr << "cur a: " << a << endl;
    int cur_bars = min(b, k-1);
    a -= (cur_bars+1) * v;
    b -= cur_bars;
    boxes++;
    if(b == 0 and a >= 0){
      boxes += (a/v) + (a%v > 0);
      a = 0;
    }
  }
  cout << boxes << endl;
}

