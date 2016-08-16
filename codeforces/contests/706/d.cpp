/*input
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11
*/


#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, no;
	node *a[2];
};

node *getNode(){
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = 0;
	temp->no = 0;
	temp->a[0] = NULL;
	temp->a[1] = NULL;
	return temp;
}




int main(void){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	char type;
	int x;
	node *root = getNode();
	for (int t= 0; t < q; t++){
		cin >> type >> x;
		if (type == '+'){
			cout << "Inserting " << x << endl;
			node *temp = root;
			for (int i = 31; i >= 0; i -= 1){
				cout << "i: " << i << endl;
				if(x&(1<<i)){
					cout << "F" << endl;
					if(temp->a[1] == NULL){
						temp->a[1] = getNode();
					}else{
						// do nothing
					}
					temp->no += 1;
					temp = temp->a[1];
				}else{
					cout << "S" << endl;
					if (temp->a[0] == NULL){
						cout << "Node 0 is null" << endl;
						cout << "Getnode" << (getNode()->val) << endl;
						temp->a[0] == getNode();
						cout << "After setting " << (temp->a[0] == NULL) << endl;
					}else{
						cout << "Dont need anything" << endl;
					}
					temp->no += 1;
					temp = temp->a[0];
				}
			}
			temp->val = x;
			cout << "Inserted " << x << endl;
		}else if (type == '-'){
			node *temp = root;
			for (int i = 31; i >= 0; i -= 1){
				if (x&(1<<i)){
					if (temp->a[1]->no < 2){
						temp->a[1] = NULL;
						break;
					}else{
						temp = temp->a[1];
					}
				}else{
					if(temp->a[0]->no < 2){
						temp->a[0] = NULL;
						break;
					}else{
						temp = temp->a[0];
					}
				}
			}
			cout << "Deleted " << x << endl;
		}else{
			string binary = "";
			node *temp = root;
			int ans = 0;
			for (int i = 31; i >= 0; i -= 1){
				if (x&(1<<i)){
					if(temp->a[0] == NULL){
						ans += (1<<i);
						temp = temp->a[1];
					}else{
						temp = temp->a[0];
					}
				}else{
					if(temp->a[1] == NULL){
						temp = temp->a[0];
					}else{
						ans += (1<<i);
						temp = temp->a[1];
					}
				}
			}
			cout << (ans^x) << endl;
		}
	}
}