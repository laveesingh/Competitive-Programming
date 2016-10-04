#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll pow2[1000001];

void setpow2(){
	pow2[0] = 1;
	for(ll i = 1; i < 1000001; i += 1){
		pow2[i] = (pow2[i-1] * 2)%mod;
	}
}

inline ll  getpow2(ll n){
	if (n <= 0) return 1;
	return pow2[n];
}

int main(void){
	setpow2();
	ll n;
	cin >> n;
	ll freq[n];
	
	freq[0] = getpow2(n) - 1;
	ll first = n-2, second = 0, ind = 1;
	while(first > second){
		freq[ind++] = getpow2(first--) - getpow2(second++);
	}
	for(int i = 1; i < (n+1)/2; i += 1){
		freq[i] += freq[i-1];
	}
	ll ans = 0, temp;
	for(int i = 0; i < n; i += 1){
		cout << (i < (n+1)/2 ? freq[i] : freq[n-i-1]) <<" ";
	}
	cout << endl;
	for(ll i = 0; i < n; i +=1){
		cin >> temp;
		ans = (ans + temp*(i < (n+1)/2 ? freq[i] : freq[n-i-1]))%mod;
	}
	cout << ans << endl;

}
