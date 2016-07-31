#include <iostream>
#include <algorithm>

using namespace std;

#define limit 5000000

int isprime[limit];

void sieve(){
	fill_n(isprime, limit,1);
	isprime[0] = isprime[1] = 0;
	for(int i = 4; i < limit; i+=2){
		isprime[i] = 0;
	}
	for(int i = 3; i < sqrt(limit)+1; i += 2){
		if(isprime[i]){
			for(int j = i*i; j < limit; j += i){
				isprime[j] = 0;
			}
		}
	}
}

int main(void){
	sieve();
	int n;
	cin >> n;
	int i = 1, j = 3;
	cout << 2 << " ";
	while(i < n){
		if(isprime[j]){
			cout << j << " ";
			i++;
		}
		j++;
		j++;
	}
	cout << endl;
}