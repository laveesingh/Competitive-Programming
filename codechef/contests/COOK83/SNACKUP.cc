#include <iostream>
#include <utility>

#include <vector>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int r = n;
        vector<pair<int, int> > store;
        for(int i = 1; i < n; i++)
            store.push_back({i, i+1});
        store.push_back({n, 1});
        cout << r << endl;
        for(int round = 0; round < r; round++){
            cout << n << endl;
            int ind = round;
            for(int judge = 1; judge <= n; judge++){
                pair<int, int> recipes = store[ind];
                ind += 1;
                ind %= n;
                cout << judge << " " << recipes.first << " " << recipes.second << endl;
            }
        }
    }
}
