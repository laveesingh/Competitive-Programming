#include <bits/stdc++.h>

using namespace std;

int main(void){
  int m, s;
  cin >> m >> s;
  if(s == 0){
    if(m == 1){
      cout << "0 0" << endl;
    } else{
      cout << "-1 -1" << endl;
    }
    return 0;
  }
  if(s > 9*m){
    cout << "-1 -1" << endl;
    return 0;
  }

  int x = m;
  int d = 9;
  map<int, int> store;
  int len = 0;
  while (d > 0){
    while((s-d) >= 0 && m > 0){
      s -= d;
      m -= 1;
      store[d]++;
      len++;
    }
    d--;
  }
  while(m > 0)
    store[0]++, m--, len++;
  if(len > x){
    cout << "len " << len << " m " << m << endl;
    cout << "-1 -1" << endl;
  }
  else{
    string largest = "";
    string smallest = "";
    for(int i = 9; i >= 0; i--)
      for(int j = 0; j < store[i]; j++)
        largest += to_string(i);
    if(store[0]){
      if(store[1]){
        smallest += "1";
        store[1]--;
      }else{
        bool found = false;
        for(int i = 2; i <= 9; i++){
          if(store[i] > 0){
            found = true;
            smallest += "1";
            store[i]--;
            store[i-1]++;
            store[0]--;
            break;
          }
        }
        if(!found){
          cout << "-1 -1" << endl;
          return 0;
        }
      }
      for(int i = 0; i <= 9; i++)
        for(int j = 0; j < store[i]; j++)
          smallest += to_string(i);
    }else{
      for(int i = 1; i <= 9; i++)
        for(int j = 0; j < store[i]; j++)
          smallest += to_string(i);
    }
    cout << smallest << " " << largest << endl;
  }
}
