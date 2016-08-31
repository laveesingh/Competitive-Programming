#include<bits/stdc++.h>
/*not ac*/
using namespace std;

#define ll long long

ll pow(ll a, ll b, ll c){
	if (b == 1) return a%c;
	if (b&1) return (a*pow(a, b-1, c))%c;
	ll x = pow(a, b/2, c);
	return (x*x)%c;
}

bool is_prime(ll n){
	if(n<2) return false;
	if(n==2) return true;
	if(n%2 == 0) return false;
	for(int i=0;i<10;i++){
		ll a= rand()%(n-1) + 1;
		if(pow(a,n-1,n) != 1){
			return false;
		}
	}
	return true;
}

ll bprime(ll n){
	if (n == 3) return 2;
	n -= (n&1 ? 2 : 1);
	while (true){
		if (is_prime(n)) return n;
		n--;
		n--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int t;
	cin>>t;
	ll n;
	while(t--){
		cin>>n;
		cout << bprime(n) << endl;
	}
}