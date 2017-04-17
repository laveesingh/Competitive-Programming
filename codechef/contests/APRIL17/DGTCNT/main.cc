#include <iostream>
#include <cstring>

using namespace std;

int a[10];

bool dislikes(int n){
  string ns = to_string(n);
  int freq[10];
  memset(freq, 0, sizeof(freq));
  for(char x: ns)
    freq[x-'0']++;
  for(int i = 0; i < 10; i += 1){
    if(freq[i] == a[i]) 
      return true;
  }
  return false;
}

int main(void){
  int t;
  cin >> t;
  while(t--){
    int l, r;
    cin >> l >> r;
    for(int i = 0; i < 10; i += 1){
      cin >> a[i];
    }
    int ans = 0;
    for(int i = l; i <= r; i += 1){
      if(dislikes(i));
      else
        ans += 1;
    }
    cout << ans << endl;
  }
}
