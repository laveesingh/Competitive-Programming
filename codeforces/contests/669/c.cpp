#include <iostream>
#include <vector>

using namespace std;

class query{
public:
	int type;
	int v1, v2, v3;
	query(){};
	query(int t, int a, int b, int c){
		type = t;
		v1 = a;
		v2 = b;
		v3 = c;
	}
};

int **a;

int main(){
	int n, m, q, t, aa, bb, cc, row, col;
	cin >> n >> m >> q;
	a = new int*[n];
	for (int i= 0; i < n; i += 1){
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			a[i][j] = 0;
		}
	}

	vector<query> queries;
	for(int i = 0; i < q; i += 1){
		cin >> t;
		if (t == 1 || t == 2){
			cin >> aa;
			queries.push_back(query(t, aa, 0, 0));
		}else{
			cin >> aa >> bb >> cc;
			queries.push_back(query(t, aa, bb, cc));
		}
	}
	// for (int i = 0; i < q; i += 1){
	// 	cout << queries[i].type << " " << queries[i].v1 << " " << queries[i].v2 << " " << queries[i].v3 << endl;
	// }

	for (int i = q-1; i >= 0; i -= 1){
		query temp = queries[i];
		if (temp.type == 1){
			row = temp.v1;
			row -= 1;
			int store = a[row][m-1];
			for (int j = m-1; j > 0; j -= 1){
				a[row][j] = a[row][j-1];
			}
			a[row][0] = store;
		}else if(temp.type == 2){
			col = temp.v1;
			col -= 1;
			int store = a[n-1][col];
			for (int j = n-1; j > 0; j -= 1){
				a[j][col] = a[j-1][col];
			}
			a[0][col] = store;
		}else{
			aa = temp.v1;
			bb = temp.v2;
			cc = temp.v3;
			// cout << "Assignment query: " << aa << " " << bb <<" " << cc << endl;
			a[aa-1][bb-1] = cc;
			// cout << "a["<<aa-1<<"]["<<bb-1<<"]: "<<a[aa-1][bb-1];
		}
	}
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}


}