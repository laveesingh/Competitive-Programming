#include <iostream>
#include <cmath>

using namespace std;

#define F(i, n) for (int i = 0; i < n;i +=1)
#define ull unsigned long long

int n, m, *a;

bool fits(ull x){
	int parts = 0, cur = 0;
	F(i,n){
		if (a[i] > x) return false;
	}
	F(i,n){
		if (cur + a[i] <= x) {
			cur += a[i];
			if(i == n-1) parts += 1;
		}
		else {
			cur = a[i];
			parts += 1;
			if(i == n-1) parts += 1;
		}


	}
	return parts <= m;
}

int main(void){
	cin >> n >> m;
	a = new int[n];
	F(i,n) cin >> a[i];
	ull lo = 0, hi = pow(10,18), mid;
	while (lo < hi){
		mid = lo + (hi-lo)/2;
		if (fits(mid)){
			hi = mid;
		}else{
			lo = mid+1;
		}
	}
	if (fits(lo))
		cout << lo << endl;
	else cout << hi << endl;
	// cout << fits(3) << endl;
}

// def case():
//  n = random.randint(1,20)
//  t = random.randint(1,n)
//  print n,t
//  for i in xrange(n):
//   print random.randint(1,t),
//  print

