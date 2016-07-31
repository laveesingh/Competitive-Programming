#include <iostream>
#include <set>

using namespace std;

int n, m;
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};

bool isvalid(int i, int j){
	if (i >= 0 && i < n && j >= 0 && j < m){
		return true;
	}
	return false;
}

int main(void){
	cin >> n >> m;
	char pcolor;
	cin >> pcolor;
	char matrix[n][m];
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			cin>> matrix[i][j];
		}
	}
	set<char> deputies;
	
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			if(matrix[i][j] == pcolor){
				for (int index = 0; index < 4; index += 1){
					if(isvalid(i+X[index],j+Y[index]) && matrix[i+X[index]][j+Y[index]] != pcolor && matrix[i+X[index]][j+Y[index]] != '.'){
						deputies.insert(matrix[i+X[index]][j+Y[index]]);
					}
				}
			}
		}
	}
	cout << deputies.size() << endl;
}