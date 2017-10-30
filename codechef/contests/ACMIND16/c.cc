#include <iostream>
using namespace std;

int main(void){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++) cin >> a[i];
    int o = 0,
        z = 0,
        x = 0,
        y = 0;
    for(int i = 0; i < n; i ++){
      if(a[i] == 0) z++;
      else if(a[i] == 1) o++;
      else if(a[i] == -1) y++;
      else x++;
    }
    if(x > 1) cout << "no" << endl;
    else if(x == 1 and y >= 1) cout << "no" << endl;
    else if(y >= 2 and o == 0) cout << "no" << endl;
    else cout << "yes" << endl;
  }
}
