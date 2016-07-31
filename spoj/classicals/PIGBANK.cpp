#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000000

class coin{
public:
	int val, weight;
	coin(){}
	coin(int v, int w){
		weight = w;
		val = v;
	}
};

bool comp(coin a, coin b){
	if (a.weight <= b.weight) return true;
	return false;
}

int minimum(int a, int b){
	if (a >= b) return b;
	return a;
}

int main(void){
	int t, wpre, wpost, n, tw, tv, w, min;

	cin >> t;
	while (t--){
		cin >> wpre >> wpost;
		w = wpost-wpre;
		cin >> n;
		coin coins[n];
		for (int  i = 0; i < n; i += 1){
			cin >> tv >> tw;
			coins[i] = coin(tv, tw);
		}
		sort(coins, coins+n, comp);
		int weights[w+1];
		fill_n(weights, w+1, INF);
		weights[0] = 0;
		for (int i = 1; i <= w; i += 1){
			min = INF;
			for (int j = 0; j < n; j += 1){
				if(i - coins[j].weight >= 0){
					min = minimum(min, weights[i-coins[j].weight]+coins[j].val);
				}
			}
			weights[i] = min;
		}
		if (weights[w] == INF){
			cout << "This is impossible." << endl;
		}else{
			cout << "The minimum amount of money in the piggy-bank is " << weights[w] <<"." << endl;
		}
	}
}