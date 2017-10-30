#include <iostream>
#include <cmath>
using namespace std;

string bin(unsigned long long n){
	if (n == 0) return "0";
	string temp = "";
	while (n > 1){
		if (n%2){
			temp.insert(0, "1");
		}else{
			temp.insert(0,"0");
		}
		n /= 2;
	}
	temp.insert(0, "1");
	return temp;
}

unsigned long long revbin(string a){
	unsigned long long temp = 0;
	int l = a.length();
	for (int i= 0; i < l; i += 1){
		if (a[i] == '1'){
			temp += pow(2, l-i-1);
		}
	}
	return temp;
}

bool isPower(unsigned long long n){
	string binary = bin(n);
	int cnt = 0;
	for (char x: binary){
		if (x == '1'){
			cnt += 1;
			if (cnt > 1) return false;
		}
	}
	return true;
}

unsigned long long predecessor(unsigned long long n){
	if (isPower(n)){
		int p = (int) log2(n);
		p -= 1;
		return pow(2, p);
	}else{
		string binary = bin(n);
		int l = binary.length();
		l -= 1;
		string num = "1";
		while (l--) num+="0";
		return revbin(num);
	}
}

void solve(unsigned long long n){
	int cnt = 0;
	while (n > 1){
		n -= predecessor(n);
		cnt += 1;
	}
	//cout << "The Count is; " << cnt << endl;
	if (cnt%2){
		cout << "Louise" << endl;
	}else{
		cout << "Richard" << endl;
	}
}

int main(void){
	int t;
	cin >> t;
	unsigned long long n;
	while (t--){
		cin >> n;
		solve(n);
	}
	
}