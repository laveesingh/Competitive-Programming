#include <iostream>
using namespace std;

int main(void){
  int n, k;
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k;
    if(k > n/2){
      cout << -1 << endl;
      continue;
    }
    int a[n+1];
    for(int i = 1; i <= n; i++)
      a[i] = i;
    for(int i = 1; i <= k; i++){
      int j = i;
      while(j <= n){
        if(j+k <= n && j+2*k > n){
          swap(a[j], a[j+k]);
          j = j+2*k;
        }else if(j+k <= n && j+2*k <= n && j+3*k <= n){
          swap(a[j], a[j+k]);
          j = j + 2*k;
        }else{
          int temp = a[j];
          a[j] = a[j+k];
          a[j+k] = a[j+2*k];
          a[j+2*k] = temp;
          j = j + 3*k;
        }
      }
    }
    for(int i = 1; i <= n; i++){
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
