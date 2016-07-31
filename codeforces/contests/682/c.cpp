#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

#define pii pair<int,int>
#define mp make_pair

class node{
}

int main(void){
	int n;
	scanf("%d", &n);
	vector<int> a[n+1];
	int val[n+1], x, y, par, chil;
	for (int i = 1; i <= n; i += 1){
		scanf("%d", &val[i]);
	}
	map<pii, int> weight;
	for (int i = 1; i < n; i += 1){
		scanf("%d %d", &x, &y);
		par = min(x, i+1);
		chil = max(x, i+1);
		node[par].push_back(chil);
		weight[mp(par, chil)] = y;

	}
}