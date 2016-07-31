#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 100000000.0
#define pif pair<int, float>
#define mp make_pair

// map<pif, float> store;

// float solve(int m, float a[], map<float, int> weight, map<float, float> price, int W, float p){
// 	if (store[mp(W,p)]) {
// 		// cout << "hit ";
// 		return store[mp(W, p)];
// 	}
// 	if (W <= 0) return p;
// 	else{
// 		float temp = INF;
// 		for (int i = 0; i < m; i += 1){
// 			float x = solve(m, a, weight, price, W-weight[a[i]], p+price[a[i]]);
// 			store[mp(W-weight[a[i]], p+price[a[i]])] = x;
// 			if (x < temp) temp = x;
// 		}
// 		return temp;
// 	}
// }

int main(void){
	int x, m;
	cin >> x >> m;
	int w[m];
	float p[m];
	map<float, int> weight;
	map<float, float> price;
	for (int i = 0; i< m; i += 1){
		cin >> w[i] >> p[i];
	}
	float a[m];
	for (int i = 0; i < m; i += 1){
		a[i] = p[i]/w[i];
		weight[a[i]] = w[i];
		price[a[i]] = p[i];
	}
	sort(a, a+m);
	int i = 0;
	int W = x;
	float P = 0;
	while (i < m && W >= 0){
		if (weight[a[i]] <= W){
			int j = 0;
			bool flag = false;
			while (j < i){
				if (price[a[j]] < price[a[i]]){
					W -= weight[a[j]];
					P += price[a[j]];
					flag = true;
					break;
				}
				j += 1;
			}
			if (flag == false){
				W -= weight[a[i]];

				P += price[a[i]];
				cout << "decreated weight by: " << weight[a[i]] << " increased price by : " << price[a[i]] << " remaining weight: " << W << endl;
				
			}
		}else{
			i += 1;
		}
	}
	if (W >= 0){
		cout << P+price[a[0]] << endl;
	}else{
		cout << P << endl;
	}
}