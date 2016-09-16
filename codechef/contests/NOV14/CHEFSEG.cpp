#include <bits/stdc++.h>

using namespace std;


double solve(double x, double k){
	double seglen = (x*1.0)/pow(2,floor(log2(k))+1);
	int shift = floor(log2(k));
	// cout << "shift: " << shift;
	// long long sec = (1<<shift);
	long long sec = ~((long long)1<<shift);
	// sec -= 1;
	// cout << " sec: " << sec;
	long long tk = k;
	long long ind = tk&sec;
	// cout << " ind: " << ind << endl;
	return seglen + (long long)2*seglen*ind;

}

int main(void){
	long long t;
	cin >> t;
	while(t--){
		double x, k;
		cin >> x >> k;
//		cout << setprecision(6) << fixed << solve(x, k) << endl;
		printf("%.6f\n",solve(x,k));
	}	
}
