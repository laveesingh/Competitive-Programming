#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

#define MAX 100000001

bool prime[MAX];

int main(void){
	memset(prime, true, MAX);
	prime[0] = prime[1] = false;
	for (int i = 4; i < MAX; i += 2){
		prime[i] = false;
	}
	for (int i = 3; i < 10001; i += 2){
		if(prime[i]){
			for (int j = i*i; j < MAX; j += i){
				prime[j] = false;
			}
		}
	}
	int dp[MAX];
	dp[0] = dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i < MAX; i += 1){
		if (prime[i]){
			dp[i] = dp[i-1]+1;
		}else{
			dp[i] = dp[i-1];
		}
	}
	int n;
	while(1){
		cin >> n;
		if (n == 0) break;
		float sec = (float)n/log(n);
		float pi =(float) dp[n];
		printf("%.1f", abs(pi-sec)/pi);
	}
}