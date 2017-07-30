#include <iostream>
#include <vector>

#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    long long t;
    cin >> t;
    long long game = 1;
    while(t--){
        long long n, x;
        cin >> x >> n;
        long long a[n];
        unordered_map<long long, vector<long long> > inds;
        for(long long i= 0; i < n; i += 1){
            cin >> a[i];
            inds[a[i]].push_back(i);
        }
        long long answer = 0;
        for(long long i = 0; i < n; i += 1){
            answer += inds[x-a[i]].size();
            if (a[i] == x-a[i]) answer--;
        }
        cout << game++ << ". " << answer/2 << endl;
    }
}