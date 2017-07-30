#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  long long t, u, v, rank;
  cin >> t;
  while(t--){
    cin >> u >> v;
    rank = ((u+v) * (u+v+1)) / 2;
    rank += u+1;
    cout << rank << endl;
  }
}
