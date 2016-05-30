#include <iostream>
#include <vector>

using namespace std;

int main(void){
   	vector<int>tocopy(3);
   	vector<int>tocopy2(3);
   	for (int i = 0; i < 3; i += 1){
   		cin >> tocopy[i] >> tocopy2[i];
   	}
   	vector<vector<int> > a(2,vector<int>(3));
   	a[0] = tocopy;
   	a[1] = tocopy2;
   	for (int i = 0; i < 2; i += 1){
   		for (int j = 0; j < 3; j += 1){
   			cout << a[i][j] << " ";
   		}
   		cout << endl;
   	}
}
