#include <bits/stdc++.h>

using namespace std;

template <class T>
class node{

public:
	T key;
	int height;
	node *left, *right;

	node(){}

	void getnode(){
		key = {};
		height = 0;
		left = right = NULL;
	}

	void getnode(T k){
		key = k;
		height = 0;
		left = right = NULL;
	}

	int getheight(){
		if(this==NULL) return 0;
		return this->height;
	}

	node* rightRotate(){
		node *x = left;
		left = x->right;
		x->right = this;
		height = max(left->getheight(), right->getheight());
		x->height = max(x->left->getheight(), x->right->getheight());
		return x;
	}

	node* leftRotate(){
		node *x = right;
		right = x->left;
		x->left = this;
		height = max(left->getheight(), right->getheight());
		x->height = max(x->left->getheight(), x->right->getheight());
		return x;
	}

};



template <class T> 
class tree{

public:
	node<T> *head = NULL;

	node<T> *insert(T key, node<T> *root){
		if(root == NULL){
			root = new node<T>();
			root->getnode(key);
			return root;
		}else if(key <= root->key){
			root->left = insert(key, root->left);
		}else{
			root->right = insert(key, root->right);
		}
		int bal = root->left->getheight() - root->right->getheight();

		/* Let's balance the tree if a node is unbalanced */

		if(bal > 1 and key < root->left->key){
			// left left unbalanced case
			return root->rightRotate();
		}
		if(bal > 1 and key > root->left->key){
			// left right unbalanced case
			root->left = (root->left)->leftRotate();
			return root->rightRotate();
		}
		if(bal < -1 and key > root->right->key){
			// right right unbalanced case
			return root->leftRotate();
		}
		if(bal < -1 and key < root->right->key){
			// right left unbalanced case
			root->right = (root->right)->rightRotate();
			return root->leftRotate();
		}
		return root;
	}


	void insert(T key){
		node<T> *root = head;
		head = insert(key, root);
	}

	bool search(T key, node<T> *temp, int& counter){
		if(temp == NULL) return false;
		if(temp->key == key) {
			cout << "Found: " << key << endl;
			return true;
		}
		if(key < temp->key) return search(key, temp->left, ++counter);
		else return search(key, temp->right, ++counter);
	}

	int search(T key){
		// cout << "Finding " << key << " .... ";
		node<T> *temp = head;
		int counter = 0;
		bool found = search(key, temp, counter);
		// cout << counter << " iterations made but " << (found ? "found" : "not found") << endl;
		return counter;
	}

	void print_in_order(node<T> *root){
		if(root == NULL) return;
		print_in_order(root->left);
		cout << root->key << " ";
		print_in_order(root->right);
	}

	void print_in_order(){
		print_in_order(head);
		cout << endl;
	}

};


int main(void){
	ios::sync_with_stdio(false);
	tree<int> bst;
	int n, q;
	cin >> n;
	int temp;
	for(int i = 0; i < n; i += 1){
		cin >> temp;
		// cout << "inserting " << temp << endl;
		bst.insert(temp);
	}
	cin >> q;
	int maxheight = 0;
	for(int i = 0; i < q; i += 1){
		cin >> temp;
		maxheight = max(maxheight, bst.search(temp));
	}
	cout << "maxheight " << maxheight << endl;
	bst.print_in_order();
}