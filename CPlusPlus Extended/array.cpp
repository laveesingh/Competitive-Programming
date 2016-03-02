#include <iostream>
#include <vector>
using namespace std;

class Array{

    public:
        int Size;
        Array(int l){
            Size = l;
        }
        int length(){
            return Size;
        }
};

int main(void){
    Array a = Array(5);
    cout << a.Size << endl;

}
