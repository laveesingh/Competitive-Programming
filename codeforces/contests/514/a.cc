#include <iostream>
#include <map>

using namespace std;

int main(void){
  string a;
  cin >> a;
  map<char, char> comp;
  comp['8'] = '1';
  comp['7'] = '2';
  comp['6'] = '3';
  comp['5'] = '4';
  comp['9'] = '0';
  for(int i = 0; i < a.length(); i++){
    if(i == 0 and a[i] == '9') continue;
    if(a[i] >= '5') a[i] = comp[a[i]];
  }
  cout << a << endl;
}
