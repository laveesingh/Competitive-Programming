#include <cstdio>
#include <algorithm>

using namespace std;

int isprime[1000001];
vector<int> primes;

void seive(){
	fill_n(isprime, 1000001, 1);
	isprime[0] = 0;
	isprime[1] = 0;
	for(int i = 4; i < 1000001; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < 1001; i += 2){
		if(isprime[i]){
			for (int j = i*i; j < 1000001; j += i){
				isprime[j] = 0;
			}
		}
	}
	primes.push_back(2);
	for (int i = 3; i < 1000001; i += 2){
		if(isprime[i]) primes.push_back(i);
	}
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}



int solve(int a, int b){
	int Gcd = gcd(a, b);
	if(isprime[Gcd]) return 2;
	int ans = 1;
	int i = 0;
	while(i < primes.size() && Gcd > 1){
		if(Gcd % primes[i] == 0){
			int freq = 0;
			while(Gcd%primes[i] == 0){
				freq++;
				Gcd /= primes[i];
			}
			ans *= (freq+1);
		}
		i += 1;
	}
	// printf("%d\n", ans);
	return ans;
}

int main(void){
	int n;
	scanf("%d", &n);
	seive();
	while(n--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
	}
}