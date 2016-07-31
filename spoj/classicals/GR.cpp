#include <iostream>

using namespace std;

int main(void){
	int n, T;
	cin >> n >> T;
	T %= 4;
	int a[n][n];
	int val = 1;
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			a[i][j] = val++;
		}
	}
	int b[n][n];
	if(T == 1){
		for(int j = 0; j < n; j += 1){
			for (int i = n-1; i >= 0; i -= 1){
				b[j][n-i-1] = a[i][j];
			}
		}
	}else if(T == 2){
		for (int i = n-1; i >= 0; i -= 1){
			for (int j = n-1; j >= 0; j -= 1){
				b[n-i-1][n-j-1] = a[i][j];
			}
		}
	}else if(T == 3){
		for(int j = n-1; j >= 0; j -= 1){
			for (int i = 0; i < n; i += 1){
				b[n-j-1][i] = a[i][j];
			}
		}
	}else{
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < n; j += 1){
				b[i][j] = a[i][j];
			}
		}
	}
	int ameen=0, sameh=0, shafeek=0, atef=0;
	for(int i= 0; i < n; i += 1){
		ameen += b[0][i];
		sameh += b[i][0];
		shafeek += b[i][n-1];
		atef += b[n-1][i];
	}
	if(ameen > sameh && ameen > shafeek && ameen > atef){
		cout << "Ameen" << endl;
	}else if(sameh > shafeek && sameh > atef){
		cout << "Sameh" << endl;
	}else if(shafeek > atef){
		cout << "Shafeek" << endl;
	}else{
		cout << "Atef" << endl;
	}
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j +=1){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}