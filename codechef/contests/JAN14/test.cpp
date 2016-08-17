#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll multmod(ll a, ll b, ll c){
	if (b == 1) return (a%c);
	if (b%2) return (a+multmod(a, b-1, c))%c;
	ll x = multmod(a, b/2, c);
	return (x+x)%c;
}
 
int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		ll L[n];
		for(int i =0 ; i < n; i += 1){
			cin >> L[i];
		}
		ll a, b, c;
		cin >> a >> b >> c;
		string ram;
		cin >> ram;
		for (int i = 0; i < n; i += 1){
			if (ram[i] == 'A'){
				for (int j = i; j < n; j += 1){
					L[j] = (L[j]+a)%c;
				}
			}else if(ram[i] == 'M'){
				for (int j = i; j < n; j += 1){
					L[j] = multmod(L[j], b, c);
				}
			}else{
				int mid = i + (n-i)/2;
				// cout << "i = " << i << endl;
				for (int j = i; j < mid; j += 1){
					// cout << "j = " << j << endl;
					swap(L[j], L[n-j+i-1]);
				}
			}
		}
		for (int i = 0; i < n; i += 1){
			cout << L[i] <<" ";
		}
		cout << endl;
	}	
}	 