#include <map>
#include <utility>
#include <deque>
#include <iostream>
#include <cstdio>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

string *a;
int n, m;

int process(int i, int j){
	int ci, cj, cw;
	map<pii, int> weight;
	deque<pii> queue;
	weight[mp(i, j)] = 0;
	queue.push_back(mp(i, j));
	while (true){
		ci = queue.front().first;
		cj = queue.front().second;
		queue.pop_front();
		cw = weight[mp(ci, cj)];
		if (ci >= n || cj >= m){
			continue;
		}
		if (a[ci][cj] == '1'){
			return cw;
		}
		pii cons[] = {mp(ci+1, cj), mp(ci, cj+1), mp(ci-1, cj), mp(cj, ci-1)};
		bool bools[] = {ci == n-1, cj == m-1, ci == 0, cj == 0};
		for (int i = 0; i < 4; i += 1){
			if (!bools[i]){
				queue.push_back(cons[i]);
				weight[cons[i]] = cw+1;
			}
		}
	}
}

int main(void){
	int t;
	scanf("%d", &t);
	char *temp;
	while (t--){
		scanf("%d %d", &n, &m);
		a = new string[n];
		temp = new char[m];
		for (int i = 0; i < n; i += 1){
			scanf("%s", temp);
			a[i] = temp;
		}
		int b[n][m];
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < m; j += 1){
				b[i][j] = process(i, j);
			}
		}
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < m ; j += 1){
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
		delete[] a;

	}
}
