#include <iostream>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a[2];
        cin >> a[0];
        cin >> a[1];
        // let's assume there's no horizontal wall at first
        int HW = 0, NHW = 0;
        bool c1 = true, c2 = true; // tell whether particular is okay till here
        for(int i = 0; i < n; i += 1){
            if(a[0][i] == '*' and a[1][i] == '*'){
                NHW = 1e9; // can't do it without horizontal wall
                break;
            }
            if(a[0][i] == '*' or a[1][i] == '*'){
                if(not c1 or not c2){
                    NHW += 1;
                    c1 = true;
                    c2 = true;
                }
                if(a[0][i] == '*')
                    c1 = false;
                if(a[1][i] == '*')
                    c2 = false;
            }
        }
        // Now let's assume there's a horizontal wall
        HW = 1;
        c1 = true, c2 = true;
        for(int i = 0; i < n; i += 1){
            if((a[0][i] == '*' and not c1) or (a[1][i] == '*' and not c2)){
                HW += 1;
                c1 = true;
                c2 = true;
            }
            if(a[0][i] == '*')
                c1 = false;
            if(a[1][i] == '*')
                c2 = false;
        }
        cout << min(HW, NHW) << endl;
    }
}