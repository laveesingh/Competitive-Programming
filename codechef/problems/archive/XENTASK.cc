#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i += 1) cin >> a[i];
    for(int i = 0; i < n; i += 1) cin >> b[i];
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i += 1){
      if(i%2){
        ans1 += a[i];
        ans2 += b[i];
      }else{
        ans1 += b[i];
        ans2 += a[i];
      }
    }
    cout << min(ans1, ans2) << endl;
  }
}
