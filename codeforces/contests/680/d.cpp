#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll cubes[1000001];

void compute_cubes(){
	for (ll i = 0; i < 100001; i += 1){
		cubes[i] = i*i*i;
	}
}

ll binary_search(ll n){
	ll lo = 1, hi = 100000, prev = 0;
	while (lo <= hi){
		// cout << "lo " << lo << " hi " << hi << endl;
		ll mid = lo + (hi-lo)/2;
		if (prev == mid){
			if (cubes[hi] <= n) return hi;
			return prev;
		}
		prev = mid;
		// cout << "cubes["<<mid<<"]: " << cubes[mid] << " n " << n << endl;
		if(cubes[mid] > n) hi = mid-1;
		else lo = mid;
		
	}
	if(cubes[hi] <= n) return hi;
	return lo;
}

ll process(ll n){
	// cout << "Entered the function " << endl;
	ll blocks = 0;
	int index;
	while (n > 0){
		// cout << "Searching for " << n << endl;
		index = lower_bound(cubes, cubes+100001, n)-cubes;
		if (cubes[index] > n) index -= 1;
		// cout << "Found: " << index << endl;
		blocks += n/cubes[index];
		n %= cubes[index];
	}
	return blocks;
}

int main(void){
	compute_cubes();
	
	ll m, blocks, max_blocks = 0, maxX = 0;
	cin >> m;
	ll limit = max(0ll, m-100001);
	// cout << "limit " << limit << endl;
	for (ll i = m; i > limit; i -= 1){
		// cout << "processing i = " << i << endl;
		blocks = process(i);
		if(blocks > max_blocks){
			max_blocks = blocks;
			maxX = i;
		}else if(blocks == max_blocks && i > maxX){
			maxX = i;
		}
	}
	cout << max_blocks << " " << maxX << endl;
}