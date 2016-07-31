#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primes;

bool isprime(int n){
	for (int i = 3; i <= (int)sqrt(n)+1; i += 2){
		if (n%i == 0) return false;
	}
	return true;
}

void compute_primes(){
	int limit = 1001;
	primes.push_back(2);
	for (int i = 3; i < limit+1; i += 2){
		if (isprime(i)) primes.push_back(i);
	}
}

int solve(int n){
	int ans = n;
	for (int fact: primes){
			// cout << "ans: " << ans << "fact: " << fact << "\t";

		if (n%fact == 0){
			// ans = (ans * (fact-1))/fact;
			ans /= fact;
			ans *= fact-1;
		
		}
		while (n%fact == 0) n /= fact;
	}
	if (n > 1){
		// ans = (ans * (n-1))/n;
		ans /= n;
		ans *= n-1;
	}
	return ans;
}

int main(void){
	int t,n;
	// cin >>t;
	scanf("%d", &t);
	compute_primes();
	while(t--){
		// cin >> n;
		// cout << solve(n) << endl;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}