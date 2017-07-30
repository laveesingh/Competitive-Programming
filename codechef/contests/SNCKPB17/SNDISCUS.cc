#include <iostream>
#include <cmath>

using namespace std;

int snakes[50][4];
int n;

inline bool vertical(int i){
    return snakes[i][0] == snakes[i][2];
}

inline bool horizontal(int i){
    return snakes[i][1] == snakes[i][3];
}

inline int dist(int i, int x, int y){
    if(horizontal(i)){
        int first = abs(snakes[i][1] - y);
        int second = 0;
        if( min(snakes[i][0], snakes[i][2]) > x || 
            max(snakes[i][0], snakes[i][2]) < x){
            second = min(abs(snakes[i][0] - x), abs(snakes[i][2] - x));
        }
        return first + second;
    }
    // its gotta be vertical now
    int first = abs(snakes[i][0] - x);
    int second = 0;
    if( min(snakes[i][1], snakes[i][3]) > y ||
        max(snakes[i][1], snakes[i][3]) < y){
        second = min(abs(snakes[i][1] - y), abs(snakes[i][3] - y));
    }
    return first + second;
}

int main(void){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < 4; j += 1){
                cin >> snakes[i][j];
            }
        }
        int min_dist = 1e5;
        for(int x = 1; x <= 50; x++){
            for(int y = 1; y <= 50; y++){
                int max_dist = 0;
                for(int i = 0; i < n; i += 1){
                    max_dist = max(max_dist, dist(i, x, y));
                }
                min_dist = min(min_dist, max_dist);
            }
        }
        cout << min_dist << endl;
    }
}