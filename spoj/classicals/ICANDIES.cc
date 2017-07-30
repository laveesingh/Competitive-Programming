#include <iostream>

using namespace std;

int solve(int n){
    for(int i = 1; i <= 10; i++){
        if((n > 5*i) && ((n-5*i) % 3 == 0)){
            return n-5*i;
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int game = 1;
    while(t--){
        int n;
        cin >> n;
        cout << "Case " << game++ << ": " << solve(n) << endl;
    }
}