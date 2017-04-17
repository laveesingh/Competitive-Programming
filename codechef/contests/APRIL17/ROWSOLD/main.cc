#include <bits/stdc++.h>

using namespace std;

int main(void){
  long long t, n;
  string a;
  cin >> t;
  while(t--){
    cin >> a;
    n = a.length();
    long long sel[n], mov[n];
    memset(sel, 0, sizeof(sel));
    memset(mov, 0, sizeof(mov));
    long long movers = 0, ind = (a[n-1] == '1' ? n-2 : n-1);
    for(long long i=n-2; i>=0; i--){
      if (a[i] == '1'){
        if(a[i+1] == '0'){
          sel[i] = movers + 1;
          mov[i] = ind - i;
          ind--;
          movers++;
        }else{
          sel[i] = sel[i+1];
          mov[i] = ind - i;
          ind--;
        }
      }
    }
    cout << (accumulate(sel, sel+n, 0ll) + accumulate(mov, mov+n, 0ll)) << endl;
  }
}
