#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int arr[n];
        for(int i = 0; i < n; i += 1){
            cin >> arr[i];
        }
        int a, b, c, d;
        for(int query = 0; query < q; query++){
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            vector<int> vec1, vec2;
            for(int i = a; i <= b; i++)
                vec1.push_back(arr[i]);
            for(int i = c; i <= d; i++)
                vec2.push_back(arr[i]);
            sort(vec1.begin(), vec1.end());
            sort(vec2.begin(), vec2.end());
            int cnt = 0;
            for(int i = 0; i <= b-a; i++)
                if (vec1[i] != vec2[i])
                    cnt++;
            if(cnt <= 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}