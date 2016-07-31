#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

#define ll long long
#define INF 1000000000

// string binary(ll n){
// 	stringstream ans;
// 	ll i = 32;
// 	while(n || i){
// 		ans << n%2;
// 		n /= 2;
// 		i -= 1;
// 	}
// 	while(i--){
// 		ans << 0;
// 	}
// 	string res = ans.str();
// 	reverse(res.begin(), res.end());
// 	return res;
// }

struct node{
	ll value;
	node *arr[2];
};

node *newNode(){
	node *temp = new node;
	temp->value	 = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(node *root, ll pre_xor){
	// string binxor = binary(pre_xor);
	node *temp = root;
	// cout << "Here we insert " << pre_xor << endl;
	for(ll i = 31; i >= 0; i -= 1){
		bool val =pre_xor & (1<<i);
		// cout << "value between 0 and 1 is " << val << endl;
		if(temp->arr[val] == NULL)
			temp->arr[val] = newNode();
		temp = temp -> arr[val];
	}
	// cout << "came out of for loop" << endl;
	temp -> value = pre_xor;
}

ll query(node *root, ll pre_xor){
	node *temp = root;
	// string binxor = binary(pre_xor);
	// cout << "Here we query " << pre_xor << endl;
	for(ll i = 31; i >= 0; i -= 1){
		bool val = pre_xor & (1<<i);
		// cout << val << endl;
		if(temp->arr[1-val] != NULL){
			temp = temp -> arr[1-val];
		}else{
			temp = temp -> arr[val];
		}
	}
	return pre_xor^(temp->value);
}

int main(void){
	ll t, n;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		ll a[n];
		for(ll i = 0; i < n; i += 1){
			scanf("%lld", &a[i]);
		}
		ll pre_xor = 0;
		ll result = -INF;
		node *root = newNode();
		insert(root, 0);
		for(int i = 0; i < n; i += 1){
			pre_xor = pre_xor ^ a[i];
			insert(root, pre_xor);
			result = max(result, query(root, pre_xor));
		}
		printf("%lld\n", result);
	}
}