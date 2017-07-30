#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

struct node{
	int pri, // priority of the node
		val, // value of the node
		no; // number of elements in the subtree rooted with this node
	node *left, *right;
};

node* getNode(int key){
	node *temp = new node;
	temp -> pri = rand();
	temp -> val = key;
	temp -> no = 0;
	temp -> left = NULL;
	temp -> right = NULL;
}

node* insert(node *root, int key){

}

int main(void){
	srand(time(NULL)); // for random integer generation

}