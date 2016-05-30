#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define INF 1000000000000000000
#define ull long long

ull distance(ull d, vector<ull> a, vector<ull> b){
	ull dist = 0;
	for (ull i = 0; i < d; i += 1){
		dist += abs(a[i]-b[i]);
	}
	return dist;
}

void Prull(vector<ull>a){
	for (ull i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}
void Prull(vector<vector<ull> > a){
	for (ull i = 0; i < a.size(); i += 1){
		Prull(a[i]);
	}
}



int main(void){
	// cout << "Value of INF: " << INF << endl;
	ull n, d;
	cin >> n >> d;
	vector<vector<ull> > poulls(n, vector<ull>(d));
	for (ull i = 0; i < n; i += 1){
		for (ull j = 0; j < d; j += 1){
			cin >> poulls[i][j];
		}
	}
	vector<vector<ull> > max_poulls(d, vector<ull>(d, -INF));
	vector<vector<ull> > min_poulls(d, vector<ull>(d, INF));
	for (ull i = 0; i < n; i += 1){
		// Prull(max_poulls[0]);
		// Prull(poulls[i]);
		if (max_poulls[0][0] < poulls[i][0]){

			max_poulls[0] = poulls[i];
		}
		if(min_poulls[0][0] > poulls[i][0]){
			min_poulls[0] = poulls[i];
		}
		if (d >= 2 && max_poulls[1][1] < poulls[i][1]){
			max_poulls[1] = poulls[i];
		}
		if(d >= 2 && min_poulls[1][1] > poulls[i][1]){
			min_poulls[1] = poulls[i];
		}
		if (d >= 3 && max_poulls[2][2] < poulls[i][2]){
			max_poulls[2] = poulls[i];
		}
		if(d >= 3 && min_poulls[2][2] > poulls[i][2]){
			min_poulls[2] = poulls[i];
		}
		if (d >= 4 && max_poulls[3][3] < poulls[i][3]){
			max_poulls[3] = poulls[i];
		}
		if(d >= 4 && min_poulls[3][3] > poulls[i][3]){
			min_poulls[3] = poulls[i];
		}
		if (d >= 5 && max_poulls[4][4] < poulls[i][4]){
			max_poulls[4] = poulls[i];
		}
		if(d >= 5 && min_poulls[4][4] > poulls[i][4]){
			min_poulls[4] = poulls[i];
		}
		if (d == 6 && max_poulls[5][5] < poulls[i][5]){
			max_poulls[5] = poulls[i];
		}
		if(d == 6 && min_poulls[5][5] > poulls[i][5]){
			min_poulls[5] = poulls[i];
		}
	}
	// cout << "max_dist : "<<endl; Prull(max_poulls);
	// cout << "min_dist : "<<endl; Prull(min_poulls);
	ull max_dist = 0;
	for(ull i = 0; i < d; i += 1){
		for(ull j = 0; j < d; j += 1){
			max_dist = max(max_dist, distance(d, max_poulls[i],max_poulls[j]));
		}
	}
	for(ull i = 0; i < d; i += 1){
		for(ull j = 0; j < d; j += 1){
			max_dist = max(max_dist, distance(d, min_poulls[i],min_poulls[j]));
		}
	}
	for(ull i = 0; i < d; i += 1){
		for(ull j = 0; j < d; j += 1){
			max_dist = max(max_dist, distance(d, max_poulls[i],min_poulls[j]));
		}
	}
	cout << max_dist << endl;


}