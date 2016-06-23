#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int *fact;

void compute_factorials(int mod){
	fact = new int[50];
	fact[0] = 1;
	for (int i = 1; i < 50; i += 1){
		fact[i] = (fact[i-1]*i)%mod;
	}
	return;
}

int pow(int a, int b, int mod){
	if (b == 0) return 1;
	if(b == 1) return a%mod;
	if(b%2) return (a*pow(a, b-1, mod))%mod;
	int x = pow(a, b/2, mod);
	return (x*x)%mod;
}

int mmi(int a, int mod){
	return pow(a, mod-2, mod);
}

vector<int> factorize(int m){
	vector<int> temp;
	for (int i = 0; i < 15; i += 1){
		if(m%primes[i] == 0){
			temp.push_back(primes[i]);
		}
	}
	return temp;
}

vector<int> represent(int n, int mod){
	vector<int> temp;
	while (n > 0){
		temp.push_back(n%mod);
		n /= mod;
	}
	// reverse(temp.begin(), temp.end());
	return temp;
}

int smallC(int n, int r, int mod){
	// cout << "Computing smallC for n " << n << " r " << r << " mod " << mod <<endl;
	if(r == 0) return 1;
	if (r == 1) return n%mod;
	int ans = 1;
	// cout << "Ans 1" << endl;
	ans = (ans * fact[n])%mod;
	// cout << "Ans 2 " << ans << endl;
	ans = (ans * mmi(fact[r], mod))%mod;
	// cout << "Ans 3 " << ans << endl;
	ans = (ans * mmi(fact[n-r], mod))%mod;
	// cout << "Ans 4 " << ans << endl;
	return ans;
}

int bigC(int n, int r, int mod){
	// cout << "Computing bigC for n " << n << " r " << r << " mod " << mod << endl;
	compute_factorials(mod);
	vector<int> N = represent(n, mod);
	vector<int> R = represent(r, mod);
	int ans = 1;
	for (int i = 0; i < R.size(); i += 1){
		ans = (ans*smallC(N[i], R[i], mod))%mod;
	}
	// cout << "Returning " << ans << endl;
	return ans;
}

int solve(int n, int r, int m){
	vector<int> mods = factorize(m);
	
	vector<int> rems;
	for (int i = 0; i < mods.size(); i += 1){
		rems.push_back(bigC(n, r, mods[i]));
	}
	// cout << "Factors and accordingly ncr is " << endl;
	// for (int i = 0; i < mods.size(); i +=1){
		// cout << mods[i] << " " << rems[i] << endl;;
	// }
	// cout << "Let's apply CRT sizes of both vectors are equal = " << (mods.size()==rems.size()) <<endl;
	int ans = 0;
	for (int i = 0; i < mods.size(); i += 1){
		ans += (rems[i] * (m/mods[i]) * mmi((m/mods[i]), mods[i]));
		// cout << "Answer " << ans << endl;
		ans %= m;
	}
	return ans;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, r, m;
		scanf("%d %d %d", &n, &r, &m);
		printf("%d\n", solve(n, r, m));
	}
	// int n = 20, r = 6, m = 7;
	// cout << "bigC: for " << n << " " << r << " " << m << " is: " << bigC(n, r, m) << endl;

}
