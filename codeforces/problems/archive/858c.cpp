#include <bits/stdc++.h>

using namespace std;

bool is_consonant(char x){
  if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return false;
  return true;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  int n = a.length();
  vector<int> inserts;
  int cons = 0;
  for(int i = 0; i < n; i++){
    if(is_consonant(a[i])){
      cons++;
    }else{
      cons = 0;
    }
    if(cons >= 3){
      if(a[i] == a[i-1] && a[i] == a[i-2]) continue;
      else{
        inserts.push_back(i);
        cons = 1;
      }
    }
  }
  reverse(inserts.begin(), inserts.end());
  for(int ind: inserts)
    a.insert(ind, " ");
  cout << a << endl;
}

