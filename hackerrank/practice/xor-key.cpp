#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

struct node{
	int val;
	set<int> indices;
	node *arr[2];
};

node *getNode(){
	node *temp = new node;
	temp -> val = 0;
	temp ->arr[0] = temp-> arr[1] = NULL;
	return temp;
}

void insert(node *root, int n, int index){
	node *temp = root;
	// cout << "Adding " << n << endl;
	for(int i = 15; i >= 0; i--){
		bool ind = n&(1<<i);
		if( temp->arr[ind] == NULL){
			temp -> arr[ind] = getNode();
		}
		temp = temp -> arr[ind];
		temp->indices.insert(index);
	}
	// cout << "This set now contains: " << *(temp->indices.begin()) << " at beginning and " << *(temp->indices.rbegin()) << " at the end: " << endl;
	temp -> val = n;
}

int query(node *root, int x, int y, int n){
	node *temp = root;
	for (int i = 15; i >= 0; i--){
		bool ind = n&(1<<i);
		// cout << "ind: " << ind << endl;
		int beg, end;
		if(temp->arr[1-ind] != NULL && 
			(
				(

					(beg=*(temp->arr[1-ind]->indices.begin()) >= x && beg <= y) || 
					(end=*(temp->arr[1-ind]->indices.rbegin()) >= x && end <= y)
				) || 
				(
					(x >= beg && x <= end) ||
					(y >= beg && y <= end)
				)
			)


		  ) 

		{
			// cout << "Got alternative: " << endl;
			temp = temp->arr[1-ind];
		}else{
			if(temp->arr[1-ind] == NULL){
				// cout << "alternative direction" << 1-ind <<" was null:" << endl;
			}else{
				// cout << "set has values: " << *(temp->arr[1-ind]->indices.begin()) << "at the beginning and " << *(temp->arr[1-ind]->indices.rbegin()) << " at the end" << endl;
			}
			if(temp->arr[ind] != NULL){

				// cout << "Going into the same direction" << endl;
				temp = temp->arr[ind];
			}else{
				// cout << "This direction is null too!" << endl;
				break;
			}
		}
	}
	// cout << "Found value: " << temp->val << endl;
	return (temp->val ^ n);
}



int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		node *root = getNode();
		int n, q, ni, qi, ai, xi, yi;
		scanf("%d %d", &n, &q);
		for(int i = 1; i <= n; i += 1){
			scanf("%d", &ni);
			insert(root, ni, i);
		}
		for (int i = 0; i < q; i += 1){
			scanf("%d %d %d", &ai, &xi, &yi);
			cout << "ai: " << ai << " xi: " << xi << " yi: " << yi << endl;
			printf("%d\n", query(root, xi, yi, ai));
		}
	}
}