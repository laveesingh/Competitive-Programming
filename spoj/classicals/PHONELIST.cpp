#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	node *arr[10];
};

node *getnode(){
	node *temp = new node;
	for (int i = 0; i < 10; i += 1){
		temp->arr[i] = NULL;
	}
	return temp;
}

// char list[10001][11];
char **list;
int n;

bool solve(){
	node *root = getnode(), *temp;
	for (int j = 0; j < n; j += 1){
		char s[11];
		strcpy(s, list[j]);
		int len = strlen(s);
		temp = root;
		for (int i = 0; i < len; i +=1){
			if(i == len-1 && temp->arr[s[i]-'0']!=NULL){
				return false;
			} else {
				if(temp->arr[s[i]-'0'] == NULL)
					temp->arr[s[i]-'0'] = getnode();
				temp = temp->arr[s[i]-'0'];
			}
		}
	}
	return true;
}

bool comp(char a[], char b[]){
	return strlen(a) > strlen(b);
}


int main(void){
	int t;
	// cin >> t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		list = new char*[n];
		for (int i = 0; i < n; i += 1){
			list[i] = new char[11];
		}
		for (int i = 0; i < n; i += 1){
			scanf("%s", list[i]);
		}
		sort(list, list+n, comp);
		if(solve()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}