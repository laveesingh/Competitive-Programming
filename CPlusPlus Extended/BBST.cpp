/*

* A self written class to perform self-balanced binary search tree operations
* Author: Lavee Singh
* Date: 15/07/16

*/


#include <bits/stdc++.h>

using namespace std;


/*
* Below is the template class for "Node" in the binary search tree
*/

template <class T>
class node{

public:
	int height; // maintains height of subtree rooted at current node
	T key; // contains data
	node *left, *right; // Both of the right and left children

	// The function below initializes a node with empty values
	void getnode(){
		height = 0;
		key = {};
		left = right = NULL;
	}

	// The functoin below initializes a node with given data as key of the node 	
	// and rest of the values are kept empty
	void getnode(T data){
		height = 0;
		key = data;
		left = right = NULL;
	}

	// finds out the height of the tree rooted at current node
	void getheight(){
		if (this == NULL) return 0;
		return this->height;
	}

	// Function below performs right rotation on current node and returns the new root
	node *rightRotate(){
		node *x = this->left;
		this->left = x->right;
		x->right = this;
		height = max(left->getheight(), right->getheight())+1;
		x->height = max(x->left->getheight(), x->right->getheight())+1;
		return x;
	}

	// Function below performs left rotation on current node and returns the new root
	node *leftRotate(){
		node *y = this->right;
		this->right = y->left;
		y->left = this;
		height = max(left->getheight(), right->getheight())+1;
		y->height = max(y->left->getheight(), y->right->getheight())+1;
		return y;
	}
};

/*
* Below is the template class for binary search tree (AVL Tree) which is self balanced
*/

template <class T>
class bst{

/*
* Here is a complete list of data members and member functions in this BST
	Data Member:
		head

	Member Functions:
		insert(key, root)
		insert(key)
		delete(key, root)
		delete(key)
		search(key, root)
		search(key)
		inorder_traversal(root)
		inorder_traversal()
*/

public:
	
	node<T> *head = NULL; // Keeps track of the root of BST

	// Recursive definition of insertion of a node into the BST
	node<T> *insert(T key, node<T> *root){
		if(root==NULL){ // We are on the leaf, let's insert the new node here
			root = new node<T>();
			root->getnode(key);
		}else if(key <= root->key){ // node needs to be inserted somewhere into the left subtree
			root->left = insert(key, root->left);
		}else{ // node needs to be inserted somewhere into the right subtree
			root->right = insert(key, root->right);
		}

		// let's check if current node is unbalanced by a factor more than 1
		int bal = root->left->getheight() - root->right->getheight(); // >=1 if unbalanced to left and <=-1 if unbalanced to right
		if (bal > 1 and key < root->left->key){ // left-left case of unbalancing
			return root->rightRotate();
		}else if(bal > 1 and key > root->left->key){ // left-right case of unbalancing
			root->left = (root->left)->leftRotate();
			return root->rightRotate();
		}else if(bal < -1 and key > root->right->key){// right-right case of unbalancing
			return root->leftRotate();
		}else if(bal < -1 and key < root->right->key){ // right-left case of unbalancing
			root->right = (root->right)->rightRotate();
			return root->leftRotate();
		}
		// node is (almost)balanced now
		return root;
	}

	// driver function to insert a node
	void insert(T key){
		node<T> *root = head;
		head = insert(key, root);
	}

	bool search(T key, node<T> *temp, int&counter){
		if(temp == NULL) return false;
		if (temp->key == key){
			return true;
		}
		if (key < temp->key) return search(key, temp->left, ++counter);
		else return search(key, temp->right, ++counter);
	}

	int search(T key){
		node<T> *temp = head;
		int counter = 0;
		bool found = search(key, temp, counter);
		return counter;
	}

	void in_order_traverse(node<T> *root){
		if(root==NULL) return;
		in_order_traverse(root->left);
		cout << root->key << " ";
		in_order_traverse(root->right);
	}

	void in_order_traverse(){
		in_order_traverse(head);
		cout << endl;
	}
};



template <typename T>
void query(T data){
	ios::sync_with_stdio(false);
	tree<T> bst;
	cout << "Initialized BST with " << T << " data type" << endl;

	cout << "Choose any of the following:" << endl;
	cout << "1. Insert into BST" << endl << "2. Delete from BST" << endl;
	cout << "3. Search from BST" << endl << "4. Print Inorder Traversal of BST" << endl;
	int choice;
	T val;
	switch(choice){
		case 1:
			cout << "Enter the value to be inserted" << endl;
			cin >> val;

	}

}