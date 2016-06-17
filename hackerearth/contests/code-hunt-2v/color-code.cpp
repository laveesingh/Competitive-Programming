#include <iostream>

using namespace std;

string hexx = "0123456789UVWXYZ";

string chex(int a){
	string ans  = "";
	// cout << a/16 << " " << a%16 << " " << hexx[a/16] << " " << hexx[a%16] << endl;
	ans += hexx[a/16];
	ans += hexx[a%16];
	return ans;
}

int main(void){
	int n;
	int r, g, b;
	cin >> n;
	for (int i = 1; i <= n; i +=1){
		cin >> r >> g >> b;
		cout << "Case " << i << ": " << chex(r) << " " << chex(g) << " " << chex(b) << endl;
	}
}