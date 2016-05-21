#include <iostream>
#include <map>

using namespace std;
#define MAX 100000001
struct node{
	int data;
	struct node *left;
	struct node *right;
}*head, *temp, *temp_node;

int parents[MAX];

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	head = (struct node*)malloc(sizeof(node));
	head -> data = a[0];
	head -> left = NULL;
	head -> right = NULL;
	// map<int, int> parents;
	
	for (int i = 1; i < n; i += 1){
		temp = head;
		while (1){
			if (a[i] > temp->data ){
				if(temp->right != NULL){
					temp = temp->right;
				}else{
					parents[a[i]] = temp->data;
					temp_node = (struct node*)malloc(sizeof(node));
					temp_node -> data=a[i];
					temp_node -> right = NULL;
					temp_node -> left = NULL;
					temp -> right = temp_node;

					break;
				}
			}else{
				if (temp-> left != NULL){
					temp = temp->left;
				}else{
					parents[a[i]] = temp->data;
					temp_node = (struct node*) malloc(sizeof(node));
					temp_node -> data=a[i];
					temp_node -> right = NULL;
					temp_node -> left = NULL;
					temp->left = temp_node;
					break;
				}
			}
		}
	}
	for (int i = 1; i < n; i += 1){
		cout << parents[a[i]] << " " ;
	}
	cout << endl;

}