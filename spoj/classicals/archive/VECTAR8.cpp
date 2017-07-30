#include <bits/stdc++.h>

using namespace std;

const int M = 1000001;

#define all(x) x.begin(), x.end()

int isprime[M];
vector<int> pprimes;

void sieve(){
	fill_n(isprime, M,1);
	isprime[0] = isprime[1] = 0;
	for(int i = 4; i < M; i += 2){
		isprime[i] = 0;
	}
	for(int i = 3; i < sqrt(M)+1; i += 2){
		if(isprime[i]){
			for(int j = i*i; j < M; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
}

int ndigits(int n){
	int d = 0;
	while(n > 0){
		d += 1;
		n /= 10;
	}
	return d;
}

void bfs(){
	int base[] = {2,3,5,7};
	for(int i = 0; i < 4; i += 1){
		pprimes.push_back(base[i]);
	}
	queue<int> stack;
	stack.push(3);
	stack.push(5);
	stack.push(7);
	while(true){
		int cur = stack.front();
		// cout << cur  << endl;
		if(!stack.empty()) stack.pop();
		if(cur > 100000) break;
		for(int i = 1; i <= 9; i += 1){
			// cout << "digits in " << cur << " are " << ndigits(cur) << endl;
			// cout << "Adding digit " << i << endl;
			int x = i*(int)pow(10, ndigits(cur)) + cur;
			// cout << "Current x " << x << endl;
			if(isprime[x]){
				pprimes.push_back(x);
				stack.push(x);
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	sieve();
	// cout << "Sieving" << endl;
	bfs();
	// cout << "All set" << endl;
	sort(all(pprimes));
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << (upper_bound(all(pprimes), n)-pprimes.begin()) << endl;
	}
}