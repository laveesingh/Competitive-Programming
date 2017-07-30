/*input
2

6

A 10

A 5

Q

A 100

R

Q

6

A 5

Q

R

Q

R

R
*/

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>

using namespace std;


int stck[100000], maxyet[100000];

int main(void){
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	for (int j = 1; j <= t; j += 1){
		// cout << "Case " << j << ":" << endl;
		printf("Case %d:\n",j);
		int n, x;
		char type;
		scanf("%d",&n);
		int sti = -1, maxi = -1;
		for (int i = 0; i < n; i += 1){
			scanf("%c",&type);
			while (type == 10) scanf("%c",&type);
			if (type == 'A'){
				scanf("%d",&x);
				stck[++sti] = x;
				if (maxi == -1){
					maxyet[++maxi] = x;
				}else{
					maxyet[maxi+1] = max(maxyet[maxi], x);
					maxi++;
				}
			}else if(type == 'R'){
				if (maxi >= 0){
					maxi--;
					sti--;
				}
			}else{
				if(maxi == -1){
					// cout << "Empty" << endl;
					printf("Empty\n");
				}else{
					// cout << maxyet[maxi] << endl;
					printf("%d\n",maxyet[maxi]);
				}
			}
		}
	}	
}