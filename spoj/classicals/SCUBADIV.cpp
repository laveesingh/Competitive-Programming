#include <iostream>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

#define INF 1000000000;
#define piii pair<pair<int, int>, int>
#define mp make_pair

// class Pair{
// public:
// 	int a,  b,  c;
// 	Pair(int x, int y, int z){
// 		a = x;
// 		b = y;
// 		c = z;
// 	}
// };	

int *weights, *nit, *ox;

int min(int a, int b){
	if (a <= b) return a;
	return b;
}

// int store[80][22][1001];
// // map<piii, int> store;

// int solve(int n, int o, int i){
// 	if (store[n][o][i]) return store[n][o][i];
// 	// if (store[mp(mp(n, o), i)]) return store[mp(mp(n,o), i)];
// 	if (n <= 0 && o <= 0) return 0;
// 	if (i == 0) return INF;
// 	// if (i == 1) return weights[i-1];
// 	// cout << "THis is not good";
// 	int temp1 = solve(n-nit[i-1], o-ox[i-1], i-1);
// 	store[n-nit[i-1]][o-ox[i-1]][i-1] = temp1;
// 	// store[mp(mp(n-nit[i-1], o-ox[i-1]),i-1)] = temp1;
// 	int temp2 = solve(n, o, i-1);
// 	store[n][o][i-1] = temp2;
// 	// store[mp(mp(n,o),i-1)] = temp2;
// 	return min(weights[i-1]+temp1, temp2);
// }

int solve(int n, int o, int I){
	int dp[n+1][o+1][I+1];
	for (int i = 0; i < n+1; i += 1){
		for (int j = 0; j < o+1; j += 1){
			for (int k = 0; k < I+1; k += 1){
				if(i<=0 && j <= 0){
					dp[i][j][k] = 0;
				}else if(k == 0){
					dp[i][j][k] = INF;
				}else{
					dp[i][j][k] = min(weights[k-1]+dp[i-nit[k-1]][j-ox[k-1]][k-1], dp[i][j][k-1]);
				}
			}
		}
	}
	return dp[n][o][I];
}

int main(void){
	int c, n, o, num, x, y, z;
	// cin >> c;
	scanf("%d",&c);
	while (c--){
		// cin >> o >> n;
		// cin >> num;
		scanf("%d %d %d", &o, &n, &num);
		weights = new int[num];
		nit = new int[num];
		ox = new int[num];
		for (int i = 0; i < num; i += 1){
			// cin >> ox[i] >> nit[i] >> weights[i];
			scanf("%d %d %d", &ox[i], &nit[i], &weights[i]);
		}
		// for (int i = 0; i < 80; i += 1){
		// 	for (int j = 0; j < 22; j += 1){
		// 		for (int k = 0; k < 1001; k += 1){
		// 			cout << store[i][j][k] << " ";
		// 		}
		// 		cout << "    ";
		// 	}
		// 	cout << endl;
		// }
		// cout << solve(n, o, num-1) << endl;
		printf("%d\n",solve(n,0,num-1));
		delete[] weights;
		delete[] nit;
		delete[] ox;
	}
}