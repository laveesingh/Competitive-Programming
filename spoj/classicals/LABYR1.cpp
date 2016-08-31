#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>


int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};
int r, c;
int **visited, **ans;
char **maze;

bool isvalid(int i, int j){
    if (i >= r or j >= c) return false;
    if (i < 0 or j < 0) return false;
    return true;
}

void dfs(pii cur){
    int x = cur.first;
    int y = cur.second;
    for (int i = 0; i < 4; i += 1){
        if (isvalid(x+X[i], y+Y[i]) and maze[x+X[i]][y+Y[i]] == '.' and !visited[x+X[i]][y+Y[i]]){
            visited[x+X[i]][y+Y[i]] = 1;
            dfs({x+X[i], y+Y[i]});
        }
    }
    for (int i = 0; i < 4; i += 1){
        ans[x][y] = max(ans[x][y], ans[x+X[i]][y+Y[i]]);
    }
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        cin >> c >> r;
        visited = new int*[r];
        ans = new int*[r];
        maze = new int*[r];
        for (int i = 0; i < r; i += 1){
            visited[i] = new int[c];
            ans[i] = new int[c];
            maze[i] = new char[c];
        }
        for (int i = 0; i < r; i += 1){
            for (int j = 0; j < c; j++){
                cin >> maze[i][j];
            }
        }
        for (int i = 0; i < r i += 1){
            fill_n(visited[i], c, 0);
        }
        for (int i = 0; i < r; i += 1){
            for (int j = 0; j < c; j++){
                ans[i][j] = (maze[i][j] == '#' ? -1 : 0);
            }
        }

        for (int i = 0; i < r; i += 1){
            for (int j = 0; j < c; j += 1){
                if (ans[i][j] == 0 and not visited[i][j]){
                    visited[i][j] = 1;     
            }
        }
    }
}