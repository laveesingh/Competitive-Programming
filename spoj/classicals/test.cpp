#include <iostream>

using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

int main(void){
	int variable = 234;
	cout << __builtin_ffs(8) << endl;
}