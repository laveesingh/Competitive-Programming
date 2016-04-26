#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

string join(char a[], int n, string delimiter){
	string temp = "";
	for (int i = 0; i < n-1; i += 1){
		temp += a[i];
		temp += delimiter;
	}
	temp += a[n-1];
	return temp;
}

string solve(string a){
	int n = a.length()/2  + 1;
	char arr[n];
	for (int i = 0; i < a.length(); i += 2){
		arr[i/2] = a[i];
	}
	sort(arr, arr+n);
	return join(arr, n, "+");
}

int main(void){
	string a  ;
	cin >> a;
	cout << solve(a) << endl;
}