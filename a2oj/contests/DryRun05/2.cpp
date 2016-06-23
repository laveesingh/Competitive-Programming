#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll pow(ll a, ll b){
	ll ans = 1;
	while(b--){
		ans *= a;
	}
	return ans;
}

ll sumdigit(ll a){
	ll ans = 0;
	while(a){
		ans += a%10;
		a /= 10;
	}
	return ans;
}

int main(void){
	ll a, b, c;
	cin >> a >> b >> c;
	vector<ll> answers;
	for(ll s = 1; s <= 81; s += 1){
		ll x = b*pow(s, a) + c;
		if(x < pow(10,9) && x > 0 && sumdigit(x)==s){
			answers.push_back(x);
		}
	}
	cout << answers.size() << endl;
	if(answers.size()){
		for (ll i = 0; i < answers.size(); i += 1){
			cout << answers[i] << " ";
		}
		cout << endl;
	}
}