#include <iostream>
#include <cmath>


using namespace std;


#define ll long long

int main(void){
	ll n,temp	;
	cin >> n;
	ll ans = 1;
	ll czcount = 0;
	int flag = 0;
	ll tzcount = 0;
	ll tocount = 0;
	for (int i = 0; i < n; i += 1){
		cin >> temp;
		if(temp == 1 && flag == 1){
			ans *= (czcount+1);
			czcount = 0;
			tocount += 1;
		}else if(temp == 1){
			flag = 1;
			czcount = 0;
			tocount += 1;
		}else{
			czcount += 1;
			tzcount += 1;
		}
	}
	if(n==1){
		if(tzcount==1){
			cout << 0 << endl;
		}else{
			cout << 1 << endl;
		}
	}else{
		if(tzcount == 0){
			cout << 1 << endl;
		}else if(tocount == 0){
			cout << 0 << endl;
		}else{
			cout << ans << endl;
		}
	}
}