#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 100000000;

void print(set<int> a){
	for (set<int>::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " " ;
	}
	cout << endl;
}

set<int> add(set<int> a, set<int> b){
	set<int> c;
	cout << "Initial sets are " << endl;
	print(a);
	print(b);
	for (set<int>::iterator it = a.begin(); it != a.end(); it++){
		if(b.find(*it) != b.end()){
			c.insert(*(it) + 1);
			b.erase(*it);
		}
	}
	for (set<int>::iterator it = b.begin(); it != b.end(); it++){
		c.insert(*it);
	}
	cout << "Set after addition is: " << endl;
	print(c);
	return c;
}


bool lt(set<int>& a, set<int>& b){
	set<int>::reverse_iterator ita = a.rend(), itb = b.rend();
	while(1){
		if(ita == a.rbegin()) return true;
		if (itb == b.rbegin()) return false;
		if(*ita < *itb) return true;
		if(*ita > *itb) return false;
		ita--;
		itb--;
	}

}

int main(void){
	int n, m, x, y, z;
	scanf("%d %d", &n, &m);
	set<int> dist[n+1][n+1];
	cout << "Created the distance table" << endl;
	set<int> temp;
	temp.insert(INF);
	for (int i = 1; i <= n; i += 1){
		for (int j = i+1; j <= n; j += 1){
			dist[i][j] = temp;
		}
	}
	cout << "Filled he distance table" << endl;
	for (int i = 0; i < m; i += 1){
		scanf("%d %d %d", &x, &y, &z);
		dist[x][y].erase(INF);
		dist[y][x].erase(INF);
		dist[x][y].insert(z);
		dist[y][x].insert(z);
	}
	set<int>::iterator it, it2;
	for (int k = 1; k <= n; k += 1){
		for (int i = 1; i <= n; i += 1){
			for (int j = i+1; j <= n; j += 1){
				cout << "i= " << i << " j= " << j << " k= " << k  << " ";
				cout << "Changed from " << *(dist[i][j].rbegin()) << " ";
				set<int> tempset = add(dist[i][k], dist[k][j]);
				if (lt(tempset, dist[i][j])){
					dist[i][j] = tempset;
				}
				cout << " to " << *(dist[i][j].rbegin()) << endl;
			}
		}
	}
	set<int> ans;
	for (int i = 1; i <= n; i += 1){
		for (int j = i+1; j <= n; j += 1){
			ans = add(ans, dist[i][j]);
		}
	}
	cout << "The answer is " << endl;
	print(ans);

}