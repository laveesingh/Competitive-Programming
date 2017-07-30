#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int inf = 1e9 + 7;
int n, m, **a, **dist, **visited;
int X[] = {0, 0, -1, -1, -1, 1, 1, 1};
int Y[] = {1, -1, 1, 0, -1, 1, 0, -1};

inline bool valid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a = new int*[n];
        dist = new int*[n];
        visited = new int*[n];
        int maximum = 0;
        for(int i = 0; i < n; i += 1){
            a[i] = new int[m];
            dist[i] = new int[m];
            visited[i] = new int[m];
            for(int j = 0; j < m; j += 1){
                cin >> a[i][j];
                maximum = max(maximum, a[i][j]);
                dist[i][j] = inf;
                visited[i][j] = 0;
            }
        }
        deque<pii> Queue;
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < m; j += 1){
                if(a[i][j] == maximum){
                    Queue.push_back({i, j});
                    dist[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        while(!Queue.empty()){
            pii cur = Queue.front();
            Queue.pop_front();
            int tempi = cur.first, tempj = cur.second;
            for(int i = 0; i < 8; i += 1){
                int ni = tempi + X[i];
                int nj = tempj + Y[i];
                if(valid(ni, nj, n, m)){
                    dist[ni][nj] = min(dist[ni][nj], dist[tempi][tempj]+1);
                    if(!visited[ni][nj]){
                        visited[ni][nj] = 1;
                        Queue.push_back({ni, nj});
                    }
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < m; j += 1){
                answer = max(answer, dist[i][j]);
            }
        }
        cout << answer << endl;
    }
}