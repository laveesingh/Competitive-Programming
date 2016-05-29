#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

#define pii pair<pair<int, int>, pair<int,int>>
#define mp make_pair

int main(void){
	int a,b,c,d;
	int total = 0;
	map<pii, int> isthere;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= a; i += 1){
		for (int j = 1; j <= b; j += 1){
			for(int k = 1; k <= c; k += 1){
				for (int l = 1; l <= d; l += 1){
					// cout << i << " " << j << " " << k << " " << l << endl;
					if ((i^j^k^l) != 0 && !isthere[mp(mp(i,j),mp(k,l))]){
						// cout << i << " " << j << " " << k << " " << l << endl;
						int temp[] = {i,j,k,l};
						total += 1;
						do{
							isthere[mp(mp(temp[0], temp[1]), mp(temp[2], temp[3]))] = 1;
						}while(next_permutation(temp, temp+4));
					}
				}
			}
		}
	}
	cout << total << endl;
}