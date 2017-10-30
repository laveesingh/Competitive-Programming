#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i = 3; i <= sqrt(n); i+=2)
    if(n%i == 0) return false;
  return true;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans;
  if(isprime(n)){
    ans = 1;
  }else if(n%2 == 0){
    ans = 2;
  }else{
    if(isprime(n-2))
      ans = 2;
    else
      ans = 3;
  }
  cout << ans << endl;
}

