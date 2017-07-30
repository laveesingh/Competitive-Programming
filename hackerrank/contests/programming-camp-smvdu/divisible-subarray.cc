#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i += 1){
        cin >> a[i];
    }
    long long ps[n];
    for(int i = 0; i < n; i += 1){
        if (i == 0){
            ps[i] = a[i];
        }else{
            ps[i] = ps[i-1] + a[i];
        }
    }
    bool done = false;
    for(int i = 0; i < n; i += 1){
        for(int j = i; j < n; j += 1){
            int sum = ps[j] - (i > 0 ? ps[i-1] : 0);
            if(sum % n == 0){
                cout << i+1 << " " << j+1 << endl;
                done = true;
                break;
            }
        }
        if(done) break;
    }
    return 0;
}
