#include <iostream>

using namespace std;

int sumHourGlass(int i, int j, int **a){
	int sum = 0;
	sum += a[i][j] + a[i][j+1]+a[i][j+2];
	sum += a[i+1][j+1];
	sum += a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
	return sum;
}

int solve(int **a){
	int temp = -923456789, x;
	for (int i = 0; i < 4; i += 1){
		for (int j = 0; j < 4; j += 1){
			x = sumHourGlass(i, j, a);
			if (x > temp) temp = x;
		}
	}
	return temp;
}

int main(void){
	int **a;
	a = new int*[6];
	for (int i = 0; i < 6; i +=1){
		a[i] = new int[6];
	}
	for (int i = 0; i < 6; i += 1){
		for (int j = 0; j < 6; j += 1){
			cin >> a[i][j];
		}
	}
	cout << solve(a) << endl;
}