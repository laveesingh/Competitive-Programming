#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  long long t, n, x;
  cin >> t;
  while(t--){
    cin >> n;
    long long negsum = 0, possum = 0, posnum = 0;
    for(long long i = 0; i < n; i += 1){
      cin >> x;
      if (x >= 0)
        posnum++, possum += x;
      else
        negsum += x;;
    }
    cout << (possum*posnum + negsum) << endl;
  }
}
