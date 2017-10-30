#include <bits/stdc++.h>

using namespace std;

const int N = 5 * 1e5 + 1;
const int LN = 20;
int mintable[LN][N], maxtable[LN][N];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, l, r;
  cin >> n >> q;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; (1<<i) <= n; i++)
    for(int j = 0; j < n; j++){
      if(i == 0){
        mintable[i][j] = arr[j];
        maxtable[i][j] = arr[j];
      }else{
        if(j+(1<<i) <= n){
          mintable[i][j] = min(mintable[i-1][j], mintable[i-1][j+(1<<(i-1))]);
          maxtable[i][j] = max(maxtable[i-1][j], maxtable[i-1][j+(1<<(i-1))]);
        }
      }
    }
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    l--, r--;
    int lg = (int)(log2(r-l+1));
    int low = min(mintable[lg][l], mintable[lg][r-(1<<lg)+1]);
    int high = max(maxtable[lg][l], maxtable[lg][r-(1<<lg)+1]);
    cout << low+high << endl;
  }
}

