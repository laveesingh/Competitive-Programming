#include <bits/stdc++.h>

using namespace std;

bool valid(int a, int b, int c){
  if(a >= b and a <= c) return true;
  return false;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, x, y;
  cin >> n >> l >> x >> y;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  bool is_x = false, is_y = false;
  for(int i = 0; i < n; i++){
    int x_search = a[i] - x;
    int y_search = a[i] - y;
    int x_ind = lower_bound(a, a+n, x_search) - a;
    int y_ind = lower_bound(a, a+n, y_search) - a;
    if(a[x_ind] == x_search) is_x = true;
    if(a[y_ind] == y_search) is_y = true;
  }
  if(is_x and is_y)
    cout << 0 << endl;
  else if(is_x)
    cout << "1\n" << y << endl;
  else if(is_y)
    cout << "1\n" << x << endl;
  else{
    int val = -1;
    bool flag = false;
    for(int i = 0; i < n; i++){
      int m1 = a[i] - x,
          m2 = a[i] + x;
      int y_ind1 = lower_bound(a, a+n, m1-y) - a;
      int y_ind2 = lower_bound(a, a+n, m1+y) - a;
      int y_ind3 = lower_bound(a, a+n, m2-y) - a;
      int y_ind4 = lower_bound(a, a+n, m2+y) - a;
      if(valid(m1, 0, l) and a[y_ind1] == m1-y) flag = true, val = m1;
      if(valid(m1, 0, l) and a[y_ind2] == m1+y) flag = true, val = m1;
      if(valid(m2, 0, l) and a[y_ind3] == m2-y) flag = true, val = m2;
      if(valid(m2, 0, l) and a[y_ind4] == m2+y) flag = true, val = m2;
    }
    if(flag)
      cout << "1\n" << val << endl;
    else
      cout << "2\n" << x << " " << y << endl;
  }
}

