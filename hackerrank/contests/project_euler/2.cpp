#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> arr;

#define MAX 40000000000000001

void fib(){
	unsigned long long a, b, temp;
	a = 0;
	b = 1;
	while (a < MAX){
		arr.push_back(a);
		temp = a;
		a = b;
		b = temp + b;
	}
}


int main(void){
	fib();
	unsigned long long sum;
	int i;
	int t;
	cin >> t;
	unsigned long long n;
	while (t--){
		sum = 0;
		cin >> n;
		for (i = 0; i < arr.size(); i += 3){
			if (arr[i] > n) break;
			sum += arr[i];
		}
		cout << sum << endl;
	}
}
