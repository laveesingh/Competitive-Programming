
void cprime_sieve(int n, int *isprime){
	fill_n(isprime, n, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i < n; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < sqrt(n)+1; i += 2){
		if(isprime[i]){
			for (int j = i*i; j < n; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
}

