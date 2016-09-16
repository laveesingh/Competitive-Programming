/*input
2 2
7 8
4 8
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, p;

// inline void print(vector<ll> a){
// 	 for(ll x: a) cerr << x << " ";
// 		cerr << endl;
// }

inline ll fits(ll mid, ll *sum, vector<ll>& v){
	// //cerr << "Checking for " << mid << endl;
	ll cursum = 0;
	v.clear();
	for(ll j = 0; j < n; j += 1){
		if(sum[j] > mid) return 1;// increase sum i.e., lo=mid+1
		if(cursum + sum[j] > mid){
			v.push_back((ll)j);
			cursum = sum[j];
		}else{
			cursum += sum[j];
		}
	}
	if(v.size() > p-1) return 1;
	return 2;
}

inline ll fits2(ll mid, ll **FM, vector<ll>& V){
	ll cursum[p];
	V.clear();
	memset(cursum, 0, sizeof(cursum[0])*p);
	for (ll i = 0; i < n; i += 1){
		for(ll j = 0; j < p; j += 1){
			if(FM[j][i] > mid){
				return 1;
			}
			if (cursum[j]+FM[j][i] > mid){
				V.push_back(i);
				for(ll k = 0; k < p; k += 1){
					cursum[k] = FM[k][i];
				}
				break;
			}else{
				cursum[j] += FM[j][i];
			}
		}
	}
	if (V.size() > p-1) return 1;
	return 2;
}

int main(void){
	cin >> n >> p;
	ll a[n][n];
	vector<ll> H, V;
	for(ll i = 0; i < n; i += 1){
		for(ll j = 0; j < n; j += 1){
			cin >> a[i][j];
		}
	}
	ll *rsum = new ll[n];
	memset(rsum, 0, sizeof(rsum[0])*n);
	for(ll i = 0; i < n; i += 1){
		for(ll j = 0; j < n; j += 1){
			rsum[i] += a[i][j];
		}
	}
	//cerr << "Enetering to first Binary Search" << endl;
	ll lo = 0, hi = (ll)pow(10,15), mid = 0;
	while (lo <= hi){
		if(mid == (lo+hi)/2) break;
		mid = (hi+lo)/2;
		// //cerr << "mid: " << mid << endl;
		ll ans = fits(mid, rsum, H);
		if(ans == 2) hi = mid;
		else lo = mid+1;
	}
	if(lo > hi) swap(lo, hi);
	if(fits(lo, rsum, H) == 2){
		//cerr << "Rowsum: " << lo << endl;
	}else{
		fits(hi, rsum, H);
		//cerr << "Rowsum: " << hi << endl;
	}
	//cerr << "H: ";print(H);

	ll **FM = new ll*[p];
	for(ll i = 0; i < p; i += 1){
		FM[i] = new ll[n];
		fill_n(FM[i], n, 0);
	}

	// line below is wiping out much more memory than needed
	
	//cerr << "Memory FM set to 0" << endl;
	for(ll col = 0; col < n; col += 1){
		for(ll row = 0; row < p-1; row += 1){
			//cerr << "col: " << col << " row: " << row << endl;
			if(row == 0){
				for(ll crow = 0; crow < H[row]; crow += 1){
					FM[row][col] += a[crow][col];
				}
			}else{
				for(ll crow = H[row-1]; crow < H[row]; crow += 1){
					FM[row][col] += a[crow][col];
				}
				if(row != 0 and row == p-2){
					//cerr << "into the last" << endl;
					//cerr << "H: "; print(H);	
					for(ll crow = H[row]; crow < n; crow += 1){
						FM[row+1][col] += a[crow][col];
					}
					//cerr << "Sigh" << endl;
				}
			}
		}
	}
	//cerr << "Created FM " << endl;
	ll *csum = new ll[n];
	memset(csum, 0, sizeof(csum[0])*n);
	for(ll i = 0; i < p; i += 1){
		for(ll j = 0; j < n; j +=1){
			csum[j] += FM[i][j];
		}
	}
	// cerr << "The Horizontally divided matrix goes here" << endl;
	// for(int i = 0; i < p; i += 1){
	// 	for(int j = 0; j < n; j += 1){
	// 		cerr << FM[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	lo = 0, hi = (ll)pow(10,15), mid = 0;
	while (lo <= hi){
		if(mid == (lo+hi)/2) break;
		mid = (lo+hi)/2;
		ll ans = fits2(mid, FM, V);
			if(ans == 2) hi = mid;
		else lo = mid+1;
	}
	if(lo > hi) swap(lo, hi);
	if(fits2(lo, FM, V) == 2){
		// No need to do anything
	}else{
		fits2(hi, FM, V);
	}

	for(ll x: H) cout << x << " ";
		cout << endl;
	for(ll x: V) cout << x << " ";
		cout << endl;

}