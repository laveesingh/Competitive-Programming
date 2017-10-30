
vector<int> sieve_of_eratosthenes(int n){
  int isprime[n+1];
  for(int i = 0; i <= n; i++) isprime[i] = 1;
  isprime[0] = isprime[1] = 0;
  for(int i = 4; i <= n; i += 2) isprime[i] = 0;
  for(int i = 3; i < sqrt(n+1)+1.5; i += 2)
    if(isprime[i])
      for(int j = i*i; j <= n; j += 2*i)
        isprime[j] = 0;
  vector<int> primes;
  primes.push_back(2);
  for(int i = 3; i <= n; i += 2)
    if(isprime[i]) primes.push_back(i);
  return primes;
}
