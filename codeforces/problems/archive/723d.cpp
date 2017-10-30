#include <bits/stdc++.h>

using namespace std;

const int N = 51;
char mat[N][N];
bool visited[N][N];
vector< vector< pair<int, int> > > components;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int n, m;

//edge
//valid
//comp

bool edge(pair<int, int> point){
  int x = point.first;
  int y = point.second;
  if(x == 0 or y == 0 or x == n-1 or y == m-1) return true;
  return false;
}

bool valid(int x, int y){
  if(x >= 0 and y >= 0 and x <= n-1 and y <= m-1) return true;
  return false;
}

bool comp(vector< pair<int, int> > first, vector< pair< int, int > > second){
  if(first.size() < second.size()) return true;
  return false;
}

void dfs(int i, int j, int index){
  for(int ind = 0; ind < 4; ind++){
    int x = i + X[ind];
    int y = j + Y[ind];
    if(valid(x, y) and mat[x][y] == '.' and !visited[x][y]){
      visited[x][y] = true;
      components[index].push_back({x, y});
      dfs(x, y, index);
    }
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> mat[i][j];
  int index = -1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(mat[i][j] == '.' and !visited[i][j]){
        index++;
        components.push_back(vector< pair<int, int> >());
        components[index].push_back({i, j});
        visited[i][j] = true;
        dfs(i, j, index);
      }
  vector< vector< pair<int, int> > > valid_components;
  for(vector< pair<int, int> > component: components){
    bool flag = true;
    for(pair<int, int> point : component){
      if(edge(point)){
        flag = false;
        break;
      }
    }
    if(flag)
      valid_components.push_back(component);
  }
  sort(valid_components.begin(), valid_components.end(), comp);
  int p = valid_components.size(), cnt = 0;
  for(int i = 0; i < p-k; i++){
    vector< pair<int, int> > component = valid_components[i];
    for(pair<int, int> point: component){
      mat[point.first][point.second] = '*', cnt++;
    }
  }
  cout << cnt << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      cout << mat[i][j];
    cout << endl;
  }
}

