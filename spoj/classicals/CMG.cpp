#include <cstdio>
#include <set>
#include <stack>
// #include <algorithm>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	for(int j = 1; j <=t; j +=1){
		printf("Case %d:\n",j);
		int n, mango, lmango;
		scanf("%d", &n);
		multiset<int> basket;
		multiset<int>::iterator it, it2;
		stack<int> nbig;
		char temp[2];
		for (int i = 0; i < n; i += 1){
			scanf("%s", temp);
			if (temp[0] == 'A') {
				scanf("%d", &mango);
				basket.insert(mango);
				nbig.push(mango);
			}else if(temp[0] == 'R'){
				if(!basket.empty()){
					lmango = nbig.top();
					nbig.pop();
					it = basket.find(lmango);
					it2 = it;
					it2++;
					basket.erase(it, it2);
				}
			}else{
				if(basket.empty()){
					printf("Empty\n");
				}else{
					printf("%d\n", *basket.rbegin());
				}
			}
		}
	}
}