#include <bits/stdc++.h>

using namespace std;

int validator(string a){
	int n = (a[0]-'0')*10+(a[1]-'0');
	n = n*pow(10,a[3]-'0');
	// cout << "Number is " << n << endl;
	return n;
}

const int N = 7e7+1;
int DP[N];


int Set(){
	DP[1] = 1;
	for(int i = 2; i < N; i++)
		DP[i] = (DP[i-1] + 1)%i + 1;
}

int main(void){
	string a;
	int n;
	Set();
	while(1){
		cin >> a;
		n = validator(a);
		if(n == 0) break;
		cout << DP[n] << endl;
	}
}
