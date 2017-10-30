#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int turn(pii prev, pii cur, pii next){
  int x1 = prev.first,
      y1 = prev.second,
      x2 = cur.first,
      y2 = cur.second,
      x3 = next.first,
      y3 = next.second;
  if(x1 == x2){
    if(y1 < y2)
      return x2 < x3;
    else
      return x2 > x3;
  }
  if(y1 == y2){
    if(x1 < x2)
      return y3 < y2;
    else
      return y3 > y2;
  }
  return 0;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y;
  cin >> n;
  pii points[n+1];
  for(int i = 0; i < n+1; i++){
    cin >> x >> y;
    points[i].first = x;
    points[i].second = y;
  }
  int Turn[n];
  int left_turns = 0, right_turns = 0;
  //for(int i = 0; i < 10; i++) cerr << "-";
  //cerr << "Turns";
  //for(int i = 0; i < 10; i++) cerr << "-";
  //cerr << endl;
  for(int i = 1; i < n-1; i++){
    if(turn(points[i-1], points[i], points[i+1])){
      Turn[i] = 1;
      right_turns++;
    }else{
      Turn[i] = 0;
      left_turns++;
    }
  }
  int water, ans = 0;
  if(left_turns > right_turns)
    water = 0;
  else
    water = 1;
  for(int i = 1; i < n-1; i++){
    if(Turn[i]){
      if(water);
      else{
        //cerr << "right turn, water left " << i << endl;
        ans++;
      }
    }else{
      if(water){
        //cerr << "left turn, water right" << i << endl;
        ans++;
      }
      else ;
    }
  }
  cout << ans << endl;
}

