/*
A utility function to set smallest prime factors for all the numbers below N
*/

int spf[N];

void set_smallest_prime_factor(){
  for(int i = 0; i < N; i += 1)
    spf[i] = i%2 ? i : 2;
  for(int i = 3; i < N; i += 2) if(spf[i] == i)
      for(int j = i; j < N; j += i)
        spf[j] = min(spf[j], i);
}
