#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  cin >> t;
  while(t--){
    int freq[8];
    fill_n(freq, 8, 0);
    //for(int i = 0; i < 8; i++) cerr << freq[i] << " ";
    //cerr << endl;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    bool dec = false;
    int cur = 0;
    bool rba = true;
    for(int i = 0; i < n; i++){
      if(i == 0){
        if(a[i] != 1){
          rba = false;
          break;
        }
        freq[a[i]]++;
      }else{
        if(!dec and a[i] == a[i-1]) freq[a[i]]++;
        if(dec and a[i] == a[i-1]) freq[a[i]]--;
        if(!dec and a[i] == a[i-1]+1 and a[i] <= 7) freq[a[i]]++;
        if(dec and a[i] == a[i-1]-1 and a[i] <= 7) freq[a[i]]--;
        if(a[i] == 7) dec = true;
      }
    }
    for(int i = 1; i < 7; i++)
      if(freq[i] != 0){
        rba = false;
        break;
      }
    if(rba) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
