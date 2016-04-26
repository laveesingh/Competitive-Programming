#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<deque<int>> a;
int n, lastans=0 ;

void q1(int x, int y){
	int i = (x^lastans)%n;
	a[i].push_back(y);
}

void q2(int x, int y){
	int i = (x^lastans)%n;
	int j = y%a[i].size();
	cout << a[i][j] << endl;
	lastans = a[i][j];
}

int main(void){
	int q, t, x, y;
	cin >> n >> q;
	deque<int> d;
	for (int i = 0; i < n; i += 1){
		a.push_back(d);
	}
	for (int i = 0; i < q; i += 1){
		cin >> t >> x >> y;
		if (t == 1) q1(x, y);
		if (t == 2) q2(x, y);
	}
}