#include <iostream>
using namespace std;

int main(void){
  int t;
  cin >> t;
  while(t--){
    int d;
    cin >> d;
    cout << d%9 + 1 << endl;
  }
}
