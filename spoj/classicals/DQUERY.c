#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
	int key;
	Node *left, *right;
};

Node* getnode(){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->key = 0;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(void){
	struct node *root = getnode();
	printf("Everything is good\nroot: %d\n", root->key);
}