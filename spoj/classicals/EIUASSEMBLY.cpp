#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define ull unsigned long long
#define pll pair<ull, ull>
#define mp make_pair

// ull *P, *M;


bool fits(ull n, ull m, ull N, vector<pll>P){
	for (int i = 0; i < N; i += 1){
		if (P[i].first >= n) return true;
		if (P[i].first < n && m < ((n-P[i].first)*P[i].second)) return false;
		m -= (n-P[i].first)*P[i].second;
	}
	return true;
}

bool comp(pll x, pll y){
	if (x.first < y.first) return true;
	if (x.first > y.first) return false;
	if (x.second > y.second) return true;
	return false;
}

void Print(vector<pll> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << "a[i]: " << a[i].first << " " << a[i].second << endl;
	}
}

int main(void){
	int t;
	// cin >> t;
	scanf("%d", &t);
	while(t--){
		bool done = false;
		ull n, m, tempa, tempb;
		// cin >> n >> m;
		scanf("%lld %lld", &n, &m);
		// int P[n], M[n];
		// P = new ull[n];
		// M = new ull[n];
		vector<pll> P;
		for (int i = 0; i < n; i += 1){
			// cin >> P[i] >> M[i];
			scanf("%lld %lld", &tempa, &tempb);
			P.push_back(mp(tempa, tempb));
		}
		// cout << "Sorting the vector." << endl;
		sort(P.begin(), P.end(), comp);
		// Print(P);
		ull lo = 0, hi = 2000000000, mid, tl, th;
		// cout << "Starting binary search.." << endl;
		while (lo <= hi){
			// cout << "lo: " << lo << "hi: " << hi << endl;
			mid = lo + (hi-lo)/2;
			if (mid == lo){
				if (fits(hi, m, n, P))
					printf("%lld\n", hi);
				else
					printf("%lld\n", mid);
				done = true;
				break;
			}
			if (fits(mid, m, n, P)){
				lo = mid;
			}else{
				hi = mid-1;
			}
		}
		// cout << "FIts 5: " << fits(5, m, n, P) << endl;
		if (done == false){
			tl = min(lo, hi);
			th = max(lo, hi);
			for (ull i = th+1; i >= 0; i -= 1){
				// cout << "Fits " << i << " " << fits(i,m,n,P) << endl;
				if (fits(i,m,n,P)) {
					cout << i << endl;
					break;
				}
			}
			// if(fits(th, m, n, P)) cout << th << endl;
			// else cout << tl << endl;
		}
	}
}

// def case():
// 	t = randint(1,10)
// 	print t
// 	for _ in xrange(t):
// 		n, m = randint(5,10), randint(25,50)
// 		print n,m
// 		for __ in xrange(n):
// 			print randint(1,10), randint(5,25)

