#include <iostream>
#include <algorithm>
#include <unordered_map>

#define umap unordered_map

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i += 1) cin >> a[i];
    sort(a, a+n);
    if(a[0] != a[1]-1)
      cout << a[0] << endl;
    else if(a[n-1] != a[n-2]+1)
      cout << a[n-1] << endl;
    else{
      umap<int, int> freq;
      for(int i = 0; i < n; i += 1){
        freq[a[i]]++;
        if(freq[a[i]] == 2){
          cout << a[i] << endl;
          break;
        }
      }
    }
  }
}
