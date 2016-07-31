#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define ll long long

map<ll, ll> factor(ll n){
	map<ll, ll> res;
	ll d = 2;
	ll freq;
	if(n%d==0){
		freq = 0;
		while(n%d==0){
			n /= d;
			freq++;
		}
		// divisors.push_back(d);
		res[d] = freq;
	}
	d += 1;
	while(d <= sqrt(n)+1){
		// cout << "In the while: d=" << d << " and n=" << n << endl;
		if(n%d == 0){
			freq = 0;
			while(n%d==0){
				n/=d;
				freq++;
			}
			res[d] = freq;
			
		}else{
			d += 2;
		}
	}
	if(n > 1){
		res[n]=1;
	}
	return res;
}

int main(void){
	ll n;
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}else{
			map<ll, ll> res = factor(n);
			for (map<ll, ll>::iterator it = res.begin(); it != res.end(); it++){
				cout << it->first << "^" << it->second << " ";
			}
			cout << endl;
		}
	}
}