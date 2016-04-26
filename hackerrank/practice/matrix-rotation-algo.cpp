#include <iostream>
#include <deque>
#include <typeinfo>

using namespace std;

int min(int n, int m){
	if (n > m){
		return m;
	}else{
		return n;
	}
}

// This function is working properly!
deque<deque<int>> lin(int **a, int m, int n, int k){
	int nol = min(m, n)/2;  // no. of layers in the matrix
	deque<deque<int>> temp;
	int startx = 0, starty = 0, x, y;
	while (startx < nol){
		deque<int> temp2;
		x = startx;
		y = starty;
		while (x < m-startx){
			temp2.push_back(a[x][y]);
			x++;
		}
		x--;
		temp2.pop_back();
		while (y < n-starty){
			temp2.push_back((int)a[x][y]);
			y++;
		}
		y--;
		temp2.pop_back();
		while (x >= startx){
			temp2.push_back((int)a[x][y]);
			x--;
		}
		x++;
		temp2.pop_back();
		while (y >=	starty){
			temp2.push_back((int)a[x][y]);
			y--;
		}
		y++;
		temp2.pop_back();
		startx++;
		starty++;

		// here starts the rotation
		int kk = k%temp2.size();
		while(kk--){
			int val = temp2.back();
			temp2.pop_back();
			temp2.push_front(val);
		}
		temp.push_back(temp2);
	}
	
	return temp;

}

// deque<int> rotate(deque<int> a, int  k){
// 	k %= a.size();
// 	while (k--){
// 		int val = a.pop_back();
// 		a.push_front(val);
// 	}
// 	return a;
// }

int** form(deque<deque<int>> a, int m, int n){
	int **temp, x, y;
	//cout << "Allocating memory for temp..." << endl;
	temp = new int*[m];
	for (int i= 0; i < m; i += 1){
		temp[i] = new int[n];
	}
	for (int i= 0; i < m; i += 1){
		for (int j = 0; j < n; j += 1){
			temp[i][j] = 0;
		}
	}
	//cout << "Done allocating memory for temp, starting to linearize." << endl;
	int startx = 0, starty = 0, i;
	int nol = min(m, n)/2;
	while (startx < nol){
		x = startx;
		y = starty;
		i = 0;
		while (x<m-startx ){ // may the condition x < m be added.
			//if (x == 0 && y == 0) cout <<"temp[0][0]:"<<a[startx][i] << endl;
			temp[x][y] = temp[x][y]==0 ? a[startx][i] : temp[x][y];
			//if (x == 0 && y == 0) cout <<"temp[0][0]:"<<temp[x][y] << endl;

			i += 1;
			x++;
		}
		x--;
		y++;
		while (y<n-starty){
			temp[x][y] = temp[x][y]==0 ? a[startx][i] : temp[x][y];
			i++;
			y++;
		}
		y--;
		x--;
		while (x>=startx){

			temp[x][y] = temp[x][y]==0 ? a[startx][i] : temp[x][y];
			i++;
			x--;
		}
		x++;
		y--;
		while (y>=starty){
			temp[x][y] = temp[x][y]==0 ? a[startx][i] : temp[x][y];
			i++;
			y--;
		}
		y++;
		startx++;
		starty++;
	}
	return temp;

}

void print(deque<int> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	int **a, **b,m,n,k;
	
	cin >> m >> n >> k;
	a = new int*[m];
	for (int i = 0; i < m; i += 1) a[i] = new int[n];
	// cout << "Printing the value of a pointer." << endl;
	// for (int i = 0; i < m; i += 1){
	// 	for (int j = 0; j < n; j += 1){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < m; i ++){
		for (int j = 0; j < n; j += 1){
			cin >> a[i][j];
		}
	}
	//cout << "Done taking input, now linearizing the matrix..."<<endl;
	deque<deque<int>> ad = lin(a, m, n,k);
	// for (int i = 0; i < ad.size(); i += 1){
	// 	print(ad[i]);
	// 	cout << endl;
	// }
	//cout << "Done linearizing and rotating, now reforming the matrix." << endl;
	b = new int*[m];
	for (int i = 0; i < m; i += 1) b[i] = new int[n];
	b = form(ad, m, n);
	//cout << "Done forming the matrix, now printing out."<< endl;
	for (int i = 0;i < m; i += 1){
		for (int j = 0; j < n; j += 1){
			cout << b[i][j] << " ";;
		}
		cout << endl;
	}
}