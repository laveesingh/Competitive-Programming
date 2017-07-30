#include <iostream>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        char prev = '$';
        int u = 0, d = 0;
        for(char s: a){
            if(prev == s) continue;
            if(s == 'U')
                prev = 'U', u += 1;
            else
                prev = 'D', d += 1;
        }
        cout << min(d, u) << endl;
    }
}