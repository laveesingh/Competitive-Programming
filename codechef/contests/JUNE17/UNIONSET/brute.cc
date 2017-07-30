#include <bits/stdc++.h>

using namespace std;

#define uset unordered_set

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, ni, temp;
    cin >> t;
    while(t--){
        // int operations = 0;
        cin >> n >> k;
        set<int> a[n];
        for(int i = 0; i < n; i += 1){
            cin >> ni;
            for(int j = 0; j < ni; j += 1){
                cin >> temp;
                a[i].insert(temp);
            }
            // operations += 2*ni;
        }
        int ans = 0;
        for(int i = 0; i < n; i += 1){
            for(int j = i+1; j < n; j += 1){
                set<int> tset(a[i].begin(), a[i].end());
                tset.insert(a[j].begin(), a[j].end());
                // operations += tset.size() + 1;
                if(tset.size() == k)
                    ans++;
            }
        }
        cout << ans << endl;
        // cerr << "Test case finished operations: " << operations << endl;
    }
}