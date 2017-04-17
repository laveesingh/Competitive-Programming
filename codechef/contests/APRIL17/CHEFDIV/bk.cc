#include <iostream>
#include <unordered_map>
#include <cmath>
#include <set>
#include <vector>
 
using namespace std;
 
#define umap unordered_map
const long long N = 1e6+1;
long long sp[N];
 
void set_shortest_prime_factors(){
	for(long long i=1; i<N; i++) sp[i] = i;
	for(long long i=2; i<N; i+=2) sp[i] = 2;
	for(long long i=3; i<sqrt(N)+1; i+=2){
		if(sp[i] == i){
			for(long long j=i*i; j<N; j+=i)
				sp[j] = min(sp[j], i);
		}
	}
}
 
long long total_divisors(long long n){
	if(n==1) return 0;
	umap<long long, long long> factors;
	while(n>1){
		factors[sp[n]]++;
		n /= sp[n];
	}
	long long total_divs = 1;
	for(auto key: factors)
		total_divs *= (key.second + 1);
	total_divs--; // for proper factors
	return total_divs;
}
 
long long max_divdiv(long long n){
	set<long long> unique_prime_factors;
	long long m = n;
	while(m > 1){
		unique_prime_factors.insert(sp[m]);
		m /= sp[m];
	}
	long long max_total_divs = 0, ret_div = -1;
	for(long long prime_factor: unique_prime_factors){
		long long divs = total_divisors(n/prime_factor);
		if(divs >= max_total_divs){
			max_total_divs = divs;
			ret_div = n/prime_factor;
		}
	}
	return ret_div;
}
 
vector<long long> all_divisors(long long a){
	vector<long long> divisors;
	if(a == 1) return divisors;
	for(long long i=2; i<=sqrt(a); i++){
		if(a%i == 0){
			divisors.push_back(i);
			if(i != a/i)
				divisors.push_back(a/i);
		}
	}
	divisors.push_back(1);
	return divisors;
}
 
long long no_of_divisors(long long a){
	if(a == 1) return 0;
	vector<long long> divisors = all_divisors(a);
	return divisors.size();
}
 
long long singleton(long long a){
	if(a == 1) return 1;
	vector<long long> divisors = all_divisors(a);
	long long ret = no_of_divisors(a)+1;
	long long max_no_div = 0, max_div = 1;
	for (long long div: divisors){
		long long nod = no_of_divisors(div);
		if (nod > max_no_div){
			max_no_div = nod;
			max_div = div;
		}
	}
  //cerr << "NBF of " << a << " is " << max_div << endl;
	return ret + singleton(max_div);
}
 
int main(void){
	ios::sync_with_stdio(false);
	set_shortest_prime_factors();
	long long a, b, n, total_divs;
	cin >> a >> b;
	long long ans = 0;
	if(a == b){
		ans = singleton(a) - 1;
	}else{
		for(long long i=a; i<=b; i++){
			n = i;
			while(n>=1){
				total_divs = total_divisors(n);
				ans += total_divs + 1;
				if(n==1) break;
				n = max_divdiv(n);
			}
			ans -= 1;
		}
	}
	cout << ans << endl;
}
 
