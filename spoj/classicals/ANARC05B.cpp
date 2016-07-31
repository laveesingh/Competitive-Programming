#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void){
	int n, m;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		int a[n];
		for (int i = 0; i < n; i += 1){
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		int b[m];
		for (int i = 0; i < m; i += 1){
			scanf("%d", &b[i]);
		}
		vector<int> bria, brib; // indexes of bridges in a and b
		for (int i = 0; i < n; i += 1){
			int ind = lower_bound(b, b+m, a[i])-b;
			if(a[i] == b[ind]){
				bria.push_back(i);
				brib.push_back(ind);
			}
		}
		if(bria.empty()){
			printf("%d\n", max(accumulate(a,a+n, 0), accumulate(b,b+m,0)));
			continue;
		}
		map<int, int> storea;
		map<int, int> storeb;
		int lastb = -1;
		for (int i = 0; i < bria.size(); i += 1){
			int summation = accumulate(a+(lastb+1), a+bria[i], 0);
			storea[bria[i]] = summation;
			lastb = bria[i];
		}
		lastb = -1;
		for (int i = 0; i < brib.size(); i += 1){
			int summation = accumulate(b+(lastb+1), b+brib[i], 0);
			storeb[brib[i]] = summation;
			lastb = brib[i];
		}
		int maxsum = 0;
		for (int i = 0; i < bria.size(); i += 1){
			maxsum += max(storea[bria[i]], storeb[brib[i]]);
			maxsum += a[bria[i]];

		}
		int sum_after_last_bridge_a = accumulate(a+(bria.back()+1), a+n, 0);
		int sum_after_last_bridge_b = accumulate(b+(brib.back()+1), b+m, 0);
		maxsum += max(sum_after_last_bridge_a, sum_after_last_bridge_b);
		printf("%d\n", maxsum);
	}
}