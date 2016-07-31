#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define limit 2000001

int isprime[limit];
int pal[limit];
int prime[limit];

void seive(){
	fill_n(isprime, limit,1);
	isprime[0]=isprime[1]=0;
	for(int i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < sqrt(limit)+1; i+=2){
		if(isprime[i]){
			for (int j = i*i; j < limit; j += i){
				isprime[j] = 0;
			}
		}
	}
	prime[0]=prime[1]=0;
	for(int i = 2; i < limit; i += 1){
		prime[i] = prime[i-1]+isprime[i];
	}
}

bool ispalin(int n){
	int revi = 0;
	int i = n;
	while(i){
		revi = (revi*10)+i%10;
		i/=10;
	}
	return n == revi;
}

int pi(int n){
	return prime[n];
}

int rub(int n){
	return pal[n];
}

int main(void){
	seive();
	pal[0] = 0;
	for (int i = 1; i < limit; i += 1){
		if(ispalin(i)){
			pal[i] = pal[i-1]+1;
		}else{
			pal[i] = pal[i-1];
		}
	}
	int p,q;
	cin >> p >> q;
	float A = (float)p/q;
	int ans = 0;
	for (int i = 1; i < limit; i += 1){
		if(pi(i) <= A*rub(i)){
			ans = max(ans, i);
		}
	}
	if(ans){
		cout << ans << endl;
	}else{
		cout << "Palindromic tree is better than splay tree" << endl;
	}
}