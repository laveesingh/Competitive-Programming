#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
const int inf = 1e9 + 7;
const int N = 51;
int n, T;
int visited[N][N], Time[N][N], Toll[N][N];
pii dp[N][N];

pii solve(int st, int en){
  if(st == en) return {0, 0};
  if(dp[st][en].first != 0) return dp[st][en];
  int mintoll = Toll[st][en], time = Time[st][en];
  for(int mid = 0; mid < n; mid++){
    if(mid == st or mid == en) continue;
    //if(visited[st][mid] or visited[mid][en]) continue;
    visited[st][mid] = 1;
    visited[mid][en] = 1;
    pii first;
    if(dp[st][mid].first == 0){
      first = solve(st, mid);
      dp[st][mid] = first;
    }else{
      first = dp[st][mid];
    }
    pii second;
    if(dp[mid][en].first == 0){
      second = solve(mid, en);
      dp[mid][en] = second;
    }else{
      second = dp[mid][en];
    }
    if(first.second + second.second <= T and first.first + second.first < mintoll){
      mintoll = first.first + second.first;
      time = first.second + second.second;
    }
    else if(first.first + second.first == mintoll && first.second + second.second < time) time = first.second + second.second;
  }
  return dp[st][en] = {mintoll, time};
}


int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> T;
  while (n or T){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> Time[i][j];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> Toll[i][j];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        visited[i][j] = 0;
      }
    pii ans = solve(0, n-1);
    cout << ans.first << " " << ans.second << endl;
    cin >> n >> T;
  }
}

