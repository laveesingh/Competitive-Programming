#include <bits/stdc++.h>

using namespace std;

#define pcii pair<char, pair<int, int> >

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int min_time = 1e9;
  vector<pcii> finals;
  for(int len = 1; len <= 1000; len++){
    int cur_height = len;
    int time = 0;
    vector<pcii> operations;
    for(int i = 0; i < n; i++){
      if(a[i] > cur_height){
        operations.push_back({'-', { i, a[i]-cur_height} } );
        time += 1;
      }else if(a[i] < cur_height){
        operations.push_back({'+', { i, cur_height-a[i]} } );
        time += 1;
      }
      cur_height += k;
    }
    if(time < min_time){
      min_time = time;
      finals = vector<pcii>(operations.begin(), operations.end());
    }
  }
  cout << min_time << endl;
  for(pcii cur : finals){
    cout << cur.first  << " "<< cur.second.first+1 << " " << cur.second.second << endl;
  }
}

