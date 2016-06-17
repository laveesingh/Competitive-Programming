#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

#define MOD 1000000007
#define ll long long

bool comp(ll a, ll b){
	if(a > b) return true;
	return false;
}

ll prod(vector<ll> pos, ll k){
	ll i = pos.size()-1;
	ll ans = 1;
	while(k--){
		ans = (ans*pos[i--])%MOD;
	}
	return ans;
}


int main(void){
	ll t;
	// cin >> t;
	scanf("%lld", &t);
	ll n, k;
	while(t--){
		scanf("%lld %lld", &n, &k);
		ll  temp;
		vector<ll> pos;
		vector<ll> neg;
		for (ll i = 0; i < n; i += 1){
			scanf("%lld", &temp);
			if(temp < 0){
				neg.push_back(temp);
			}else if(temp > 0){
				pos.push_back(temp);
			}
		}
		sort(pos.begin(), pos.end());
		ll ans;
		if(neg.size() < 2){
			 ans = prod(pos, k);
		}else{
			sort(neg.begin(), neg.end(), comp);
			 ans = 1;
			while(k > 0 && neg.size() > 1 && pos.size() > 0){
				if(k%2){
					ans = (ans*pos.back())%MOD;
					pos.pop_back();
					k--;
				}else{
					if(k > 1 && pos.size() > 1 && neg[neg.size()-1]*neg[neg.size()-2] > pos[pos.size()-1]*pos[pos.size()-2]){
						ans = (ans*neg[neg.size()-1])%MOD;
						ans = (ans*neg[neg.size()-2])%MOD;
						neg.pop_back();
						neg.pop_back();
						k -= 2;
					}else if(k > 0){
						ans = (ans*pos[pos.size()-1])%MOD;
						pos.pop_back();
						k--;
					}
				}
			}
			if(k){
				// cout << "Entered if" << endl;
				if(neg.size() < 1){
					while(k--){
						ans = (ans*pos.back())%MOD;
						pos.pop_back();
					}
				}else{
					// cout << "Entered if-else"<<endl;
					while(k){
						if(k > 2){
							// cout << "Entered ifelseif"<<endl;
							ans = (ans*neg.back())%MOD;
							neg.pop_back();
							k--;
							ans = (ans*neg.back())%MOD;
							neg.pop_back();
							k--;
						}
						if(k==1){
							// cout<<"Enered ifelseiff"<<endl;
							ans = (ans*neg[0])%MOD;
							k--;
						}
					}
				}
			}
		}
		cout << (ans+MOD)%MOD << endl;

	}
}