#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;


const int N = 2501;
// vector<int> a[N];
int a[N][N];
int limit[N];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, ni, temp;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        // for(int i = 0; i < n; i += 1)
        //     a[i].clear();
        for(int i = 0; i < n; i += 1){
            scanf("%d", &ni);
            limit[i] = ni;
            for(int j = 0; j < ni; j += 1){
                // scanf("%d", &temp);
                scanf("%d", &a[i][j]);
                // a[i].push_back(temp);
            }
        }
        for(int i = 0; i < n; i += 1){
            // sort(a[i].begin(), a[i].end());
            sort(a[i], a[i]+limit[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i += 1){
            for(int j = i+1; j < n; j += 1){
                int x = 0, y = 0;
                int expected = 1;
                bool flag = true;
                while(x < limit[i] || y < limit[j]){
                    if(x < limit[i] && a[i][x] == expected){
                        if(y < limit[j] && a[j][y] == expected){
                            y++;
                        }
                        x++;
                        expected++;
                    }else if(y < limit[j] && a[j][y] == expected){
                        y++;
                        expected++;
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag && expected == k+1){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}