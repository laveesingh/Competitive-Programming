#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main(void){
    int a[] = {1,3,5,6,7,9};
    int b[] = {2,3,4,5,8,9};
    int c[20];
    int *it = set_symmetric_difference(a,a+6, b, b+6, c);
    while(it-- != c){
        cout << *(it) << endl;
    }
}