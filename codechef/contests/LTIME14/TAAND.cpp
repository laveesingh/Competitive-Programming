#include <bits/stdc++.h>
 
using namespace std;
 
class node{
public:
	bool leaf = false;
	node *z=NULL, *o=NULL;
};
 
int bintoint(vector<int> stack){
	int ans = 0;
	for (int i = 30; i >= 0; i--){
		ans += (1<<i)*stack[30-i];
	}
	return ans;
}
 
void print(vector<int> a){
	for(int i: a){
		cout << i << " ";
	}
	cout << endl;
}
 
// void print(node *a){
// 	if (a->z == NULL and a->o == NULL) {
// 		cout << " NULL | NULL "
// 		return;
// 	}else{
// 		print (a->z);
// 		if (a->z == NULL)
// 			cout << "NULL | 1"
// 		print (a->o);
// 	}
 
 
// }
 
int main(void){
	ios::sync_with_stdio(false);
	
	node *root = new node, *cur;
	int n;
	cin >> n;
	int ans = 0, temp;
	for (int inp = 0; inp < n; inp++){
		cin >> temp;
		cur = root;
		vector<int> stack;
		for (int i = 30; i >= 0; i--){
			if((1<<i)&temp){
				if(cur->o != NULL){
					stack.push_back(1);
				}else{
					stack.push_back(0);
				}
				if(cur->o == NULL) cur->o = new node;
			cur = cur->o;
			}else{
				stack.push_back(0);
				if(cur->z == NULL) cur->z = new node;
				cur = cur->z;
			}
			// cout << "Current stack: ";
			// print(stack);
		}
		ans = max(ans, bintoint(stack));
	}
	cout << ans << endl;
}
 
