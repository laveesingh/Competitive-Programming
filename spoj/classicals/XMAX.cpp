#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

struct node{
	ll val;
	node *arr[2];
};

node *getNode(){
	node *temp = new node;
	temp->val = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(node *root, ll n){
	node *temp = root;
	for(ll i = 63; i >= 0; i--){
		bool ind = n&(1<<i);
		if(temp->arr[ind] == NULL){
			temp->arr[ind] = getNode();
		}
		temp = temp -> arr[ind];
	}
	temp->val = n;
}

ll maxor(node *root, ll n){
	node *temp = root;
	for(ll i = 63; i >= 0; i--){
		bool ind = n&(1<<i);
		if(temp->arr[1-ind] == NULL){
			temp = temp->arr[ind];
		}else{
			temp = temp->arr[1-ind];
		}
	}
	return n^temp->val;
}



int main(void){
	ll n;
	scanf("%lld", &n);
	node *root = getNode();
	ll temp;
	scanf("%lld", &temp);
	insert(root, temp);
	ll maximumxor = 0, maxelem=0;
	maxelem = max(maxelem, temp);
	for (ll i = 1; i < n; i += 1){
		scanf("%lld", &temp);
		maxelem = max(maxelem, temp);
		// cout << "Querying " << temp << " ";
		ll cxor = maxor(root, temp);
		// cout << "Inserting " << temp <<  " ";
		insert(root, temp);
		// cout << "Inserting " << cxor << " ";
		insert(root, cxor);
		maximumxor = max(maximumxor, cxor);
		// cout << "Done for this once " << endl;
	}
	// cout << "Out of this loop" << endl;
	printf("%lld\n", max(maximumxor, maxelem));
}