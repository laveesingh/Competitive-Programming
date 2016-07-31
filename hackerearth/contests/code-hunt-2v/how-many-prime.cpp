#include <iostream>
#include <algorithm>

using namespace std;

int isprime[1000000];

void set_prime(){
	fill_n(isprime, 1000000, 1);
	isprime[0] = 0;
	isprime[1] = 0;
	for (int i = 4; i < 1000000; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < 1001; i += 2){
		if(isprime[i]){
			for (int j = i*i; j < 1000000; j += i){
				isprime[j] = 0;
			}
		}
	}
}

void solve(int n){
	int x = (n-1)/2;
	int y = n - x;
	while((!isprime[x] || !isprime[y])){
		x -= 1;
		y += 1;
	}
	if((x >= 0 && y >= 0) && isprime[x] && isprime[y]){
		cout << x << " " << y << endl;
	}else{
		cout << "-1 -1" << endl;
	}

}

int main(void){
	int t,n;
	set_prime();
	cin >> t;
	while(t--){
		cin >> n;
		solve(n);
	}
}