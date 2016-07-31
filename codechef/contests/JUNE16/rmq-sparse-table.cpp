#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100

int dp[MAX][MAX];

// void preprocess(int arr[], int n){
// 	for (int i = 0; i < n; i += 1){
// 		dp[i][0] = i;
// 	}
// 	for (int j = 1; (1<<j)<=n; j+=1){
// 		for (int i = 0; (i+(1<<j)-1) < n; i += 1){
// 			if(arr[dp[i][j-1]] < arr[dp[i+(1<<(j-1))][j-1]])
// 				dp[i][j] = dp[i][j-1];
// 			else
// 				dp[i][j] = dp[i+(1<<(j-1))][j-1];
// 		}
// 	}
// }

void preprocess(int arr[], int n){
	for (int i = 0; i < n; i += 1){
		dp[i][0] = i;
	}
	for (int j = 1; pow(2,j) <= n; j += 1){
		for (int i = 0; (i+pow(2,j)-1) < n; i += 1){
			if(arr[dp[i][j-1]] < arr[dp[i+(int)pow(2,j-1)][j-1]]){
				dp[i][j] = dp[i][j-1];
			}else{
				dp[i][j] = dp[i+(int)pow(2,j-1)][j-1];
			}
		}
	}
}

// int query(int arr[], int L, int R){
// 	int j = (int)log2(R-L+1);
// 	if(arr[dp[L][j]] <= arr[dp[R-(int)pow(2,j)+1][j]])
// 		return arr[dp[L][j]];
// 	return arr[dp[R-(int)pow(2,j)+1][j]];
// }

int query(int arr[], int i, int j){
	int k = log2(j-i+1);
	if(arr[dp[i][k]] <= arr[dp[j-(int)pow(2,k)+1][k]]){
		return arr[dp[i][k]];
	}
	return arr[dp[j-(int)pow(2,k)+1][k]];
}

int main(void){
	int a[] = {7,2,3,0,5,10,3,12,18};
	int n = sizeof(a)/sizeof(a[0]);
	preprocess(a, n);
	int i, j;
	do{
		cin >> i >> j;
		cout << query(a, i, j) << endl;
	}while(1);
}