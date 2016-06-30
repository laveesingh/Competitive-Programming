#include <iostream>
#include <algorithm>

using namespace std;

int result;

struct node{
	int key, height, size;
	node *left, *right;
};

int height(node *n){
	if (n == NULL) return 0;
	return n->height;
}

int size(node *n){
	if (n == NULL) return 0;
	return n->size;
}

node *newNode(int key){
	node *temp = new node;
	temp->key = key;
	temp->height = temp->size = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node *rightRotate(node *y){
	node *x = y->left;
	node *T1 = x -> right;

	x -> right = y;
	y -> left = T1;

	x -> height = max(height(x->left), height(x->right))+1;
	y -> height = max(height(y->left), height(y->right))+1;

	x -> size = size(x->left) + size(x->right) + 1;
	y -> size = size(y->left) + size(y->right) + 1;

	return x;
}

node *leftRotate(node *x){
	node *y = x -> right;
	node *T1 = y -> left;

	y->left = x;
	x->right = T1;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	x->size = size(x->left) + size(x->right) + 1;
	y->size = size(y->left) + size(y->right) + 1;

	return y;
}

int getBalance(node *n){
	if (n == NULL) return 0;
	return height(n->left) - height(n->right);
}

// need to globalize result
node *insert(node *root, int key){
	node *temp = root;
	if (temp == NULL){
		temp = newNode(key);
		return temp;
	}
	if (key < temp -> key){
		temp -> left = insert(temp->left, key);
		result += size(temp->right) + 1;
	} else {
		temp-> right = insert(temp->right, key);
	}
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	temp-> size = size(temp->left) + size(temp->right) + 1;

	int balance = getBalance(temp);

	if(balance > 1 && key < temp->left->key) return rightRotate(temp);
	if(balance < -1 && key > temp->right->key) return leftRotate(temp);
	if(balance > 1 && key > temp->left->key){
		temp->left = leftRotate(temp->left);
		return rightRotate(temp);
	}
	if(balance < -1 && key < temp->right->key){
		temp->right = rightRotate(temp->right);
		return leftRotate(temp);
	}
	return temp;
}

int getInvCount(int arr[], int n){
	node *root = NULL;
	result = 0;
	for (int i = 0; i < n; i += 1){
		root = insert(root, arr[i]);
	}
	return result;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for (int i =0;  i < n; i +=1){
			cin >> a[i];
		}
		cout << getInvCount(a, n) << endl;
	}
}