#include <cstdio>
#include <stack>

using namespace std;

#define ll long long

int main(void){
	ll n;
	while(1){
		scanf("%lld", &n);
		if(n == 0) break;
		ll a[n];
		for (ll i = 0; i < n; i += 1){
			scanf("%lld", &a[i]);
		}
		stack<ll> st;
		ll i = 0;
		ll max_area = 0;
		while (i < n){
			if(st.empty() || a[st.top()] <= a[i]){
				st.push(i++);
			}else{
				ll top = st.top();
				st.pop();
				ll cur_area = a[top]*(st.empty() ? i : i-st.top()-1);
				if(max_area < cur_area)
					max_area = cur_area;
			}
		}
		while(!st.empty()){
			ll top = st.top();
			st.pop();
			ll cur_area = a[top]*(st.empty() ? i : i-st.top()-1);
			if(max_area < cur_area)
				max_area = cur_area;
		}
		printf("%lld\n", max_area);
	}
}