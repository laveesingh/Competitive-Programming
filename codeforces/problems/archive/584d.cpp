#include <bits/stdc++.h>

using namespace std;

int is_prime(int n){
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i = 3; i <= sqrt(n); i += 2)
    if(n%i == 0) return false;
  return true;
}

int nearest_prime(int n){
  int start = n;
  if(n%2 == 0) start--;
  while(n > 0){
    if(is_prime(n)) return n;
    n -= 2;
  }
  return -1;
}

pair<int, int> prime_pair(int n){
  for(int i = 3; i < 10000; i += 2){
    int j = n - i;
    if(is_prime(i) and is_prime(j)) return {i, j};
  }
  return {-1, -1};
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x = nearest_prime(n);
  int diff = n - x;
  if(diff == 0){
    cout << "1\n" << n << endl;
  }else if(diff == 2){
    cout << 2 << endl;
    cout << 2 << " " << n - diff << endl;
  }else if(diff == 4){
    cout << 3 << endl;
    cout << 2 << " " << 2 << " " << n - diff << endl;
  }else{
    cout << 3 << endl;
    pair<int, int> ppair = prime_pair(diff);
    cout << x << " " << ppair.first << " " << ppair.second << endl;
  }
}

