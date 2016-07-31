#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int comp = n/7;
	int rem = n % 7;
	int max = 2*comp, min = 2*comp;
	if (rem == 1){
		max += 1;
		min += 0;
	}else if(rem >= 2 && rem != 6){
		max += 2;
		min += 0;
	}else if(rem == 6){
		max += 2;
		min += 1;
	}
	cout << min << " " << max << endl;
}