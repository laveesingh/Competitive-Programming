#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
    int no, temp;
    cin >> no;
    float z=0, p=0, n=0;
    for (int i = 0; i < no ; i += 1){
        cin >> temp;
        if (temp > 0){
            p += 1;
        }else if(temp < 0){
            n += 1;
        }else{
            z += 1;
        }
    }
    printf("%.6f\n",(p/no));
    printf("%.6f\n",(n/no));
    printf("%.6f\n",(z/no));
}
