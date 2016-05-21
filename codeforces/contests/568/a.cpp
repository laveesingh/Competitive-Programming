#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

#define M 100000

using namespace std;

int isprime[M];
int ispal[M];
vector<int> primes;
vector<int> pals;
// map<int, int> primesupto;
// map<int, int> palsupto;

int primesupto[M];
int palsupto[M];

void Print(vector<int> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << a[i] << " " ;
	}
	cout << endl;
}

string reversed(string a){
	reverse(a.begin(), a.end());
	return a;
}

bool is_pal(int n){
	string ns = to_string(n);
	string copy = reversed(ns);
	return (copy == ns);
}

void comp_prime(){
	fill_n(isprime, M, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i < (int) sqrt(M)+1; i += 1){
		if (isprime[i]){
			for (int j = i*i; j < M; j += i){
				isprime[j] = 0;
			}
		}
	}
	primes.push_back(2);
	for (int i = 3; i < M; i += 2){
		if(isprime[i]){
			primes.push_back(i);
		}
	}
	// Print(primes);
}

void comp_pals(){
	fill_n(ispal, M, 0);
	for (int i = 1; i < M; i += 1){
		if (is_pal(i)){
			pals.push_back(i);
			ispal[i] = 1;
		}
	}
	// Print(pals);
}


void comp_primes_upto(){
	int total = 0;
	for (int i = 0; i < M; i += 1){
		if (isprime[i] == 1){
			primesupto[i] = ++total;
		}else{
			primesupto[i] = total;
		}
	}
	// for (int i = 0; i < 100; i += 1){
	// 	cout << i << " " << isprime[i] << endl;
	// }
}

void comp_pals_upto(){
	int total = 0;
	for (int i = 0; i < M; i += 1){
		if (ispal[i] == 1){
			palsupto[i] = ++total;
		}else{
			palsupto[i] = total;
		}
	}
}

int solve(int p, int q){
	float A = p/(float)q;
	int x, y;
	for (int i = M; i >= 0; i -= 1){
		x = primesupto[i];
		y = palsupto[i];
		if ((float)x/(float)y <= A) return i;
	}
	return -1;
}


int main(void){
	comp_pals();
	comp_prime();
	comp_primes_upto();
	comp_pals_upto();
	// cout << primesupto[40] << endl;
	// cout << palsupto[40] << endl;

	int p, q;
	cin >> p >> q;
	
	int ans = solve(p, q);
	if (ans == -1){
		cout << "Palindromic tree is better than splay tree" << endl;
	}else{
		cout << ans << endl;
	}
}