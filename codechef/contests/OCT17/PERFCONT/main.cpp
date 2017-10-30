#include <iostream>
using namespace std;

const int N = 1e3;
int arr[N];
string solve(int n, int p){
  int cw = 0, hrd = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] <= p/10) hrd++;
    else if(arr[i] >= p/2) cw++;
  }
  if(hrd == 2 and cw == 1) return "yes";
  return "no";
}

int main(void){
  int t, n, p;
  cin >> t;
  while(t--){
    cin >> n >> p;
    cout << solve(n, p) << endl;
  }
}
