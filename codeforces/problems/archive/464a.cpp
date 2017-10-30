#include <bits/stdc++.h>

using namespace std;

string solve1(string a, int p){
  int n = a.length();
  for(int i = n-1; i >= 0; i--){
    string b(a.begin(), a.end());
    while(b[i] < 'z' && b[i] < 'a'+p-1){
      b[i]++;
      //cerr << "i: " << i << " Current string " << b << endl;
      if(i > 0 && b[i] == b[i-1]) continue;
      if(i > 1 && b[i] == b[i-2]) continue;
      if(b[i] == 'b'){
        int arr1[3] = { 'b', 'c', 'a' };
        if(i > 0 && b[i-1] == 'a'){
          for(int j = 1; i+j < n; j++){
            b[i+j] = arr1[j%3];
          }
          return b;
        }
        int arr2[3] = { 'b', 'a', 'c' };
        if(i > 0 && b[i-1] == 'c'){
          for(int j = 1; i+j < n; j++){
            b[i+j] = arr2[j%3];
          }
          return b;
        }
        for(int j = 1; i+j < n; j++){
          b[i+j] = arr2[j%3];
        }
        return b;
      }
      int arr3[3] = { 'c', 'b', 'a' };
      if(i > 0 && b[i-1] == 'a'){
        for(int j = 1; i+j < n; j++){
          b[i+j] = arr3[j%3];
        }
        return b;
      }
      int arr4[3] = { 'c', 'a', 'b' };
      for(int j = 1; i+j < n; j++){
        b[i+j] = arr4[j%3];
      }
      return b;
    }
  }
  return "NO";
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  cin >> n >> p;
  string a;
  cin >> a;
  cout << solve1(a, p) << endl;
}

