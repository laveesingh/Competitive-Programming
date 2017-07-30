#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;

class job{
public:
	int start, end, price;
	job(){}
	job(int st, int en, int pri){
		start = st;
		end = en;
		price = pri;
	}

};	

job a[10001];



int solve(int n){
	int dp[n];
	for (int i = 0; i<n; i += 1){
		dp[i] = a[i].price;
	}
	for (int i = 1; i < n; i += 1){
		for (int j = 0; j < i; j += 1){
			if (a[j].end <= a[i].start){
				dp[i] = max(dp[i], a[i].price + dp[j]);
			}
		}
	}
	return *max_element(dp, dp+n);
}

bool comp(job a, job b){
	if(a.end == b.end){
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, st, end, pri;
		scanf("%d", &n);
		for (int i = 0; i < n; i += 1){
			scanf("%d %d %d", &st, &end, &pri);
			a[i] = job(st, st+end, pri);
		}
		sort(a, a+n, comp);
		printf("%d\n", solve(n));
	}
}