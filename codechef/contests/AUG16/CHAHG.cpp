/*input
1
5
3380 4982
194 1875
4248 5861
8686 709
3933 3911
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define inf 1000000000ll

ll *H, *M;

/*
The function below:
	LGLGL... type zig-zag will return 1
	GLGLG... type zig-zag will return 2
*/

ll zig_zag(ll a[], ll n){
	if (a[0] == a[1]) return 0;
	if(a[0] < a[1]){  // LGLGL... type zig zag
		for(ll i = 1; i < n; i += 2){
			if(i < n-1){
				if(a[i] <= a[i-1] or a[i] <= a[i+1]){
					return 0;
				}
			}else{
				if(a[i] <= a[i-1]){
					return 0;
				}
			}
		}
		return 1;
	}else{
		for (ll i = 1; i < n; i += 2){
			if (i < n-1){
				if(a[i] >= a[i-1] or a[i] >= a[i+1]){
					return 0;
				}
			}else{
				if(a[i] >= a[i-1]){
					return 0;
				}
			}
		}
		return 2; // GLGLG... type zig_zag
	}
}

ll fits(ll a[], ll b[], ll n, ll t){
	ll c[n];
	for (ll i = 0; i < n; i += 1){
		c[i] = a[i]+b[i]*t;
	}
	return zig_zag(c, n);
}

ll flip(ll a){
	if (a == 1) return 2;
	return 1;
}


int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
		ll n, tempa, tempb;
		cin >> n;
		if (n == 1){
			cout << 1 << endl;
			cin >> tempa >> tempb;
			cout << "0 Inf" << endl;
			continue;
		}
		H = new ll[n];
		M = new ll[n];
		for (ll i = 0; i < n; i += 1){
			cin >> H[i] >> M[i];
		}
		ll type;
		if(type = zig_zag(H, n)){
			/*
				Now we would like to know at what time they wouldn't be zig zag anymore. 
				Since we don't know, so let's guess it using binary search
			*/
			// cout << "The sequence is zigzag of type " << type << endl;
			vector<pii> vi;
			ll hi = (ll)pow(10,9), lo = 0ll, t=0;
			if (fits(H, M, n, hi) == type){
				// cout << "zero to infinite" << endl;
				vi.push_back({0,inf});
			}else{
				// cout << "Doesn't fit in zero to infinite interval, so let's find out when will it be destroyed as zig zag" << endl;
				while(lo <= hi){
					if (t == lo + (hi-lo)/2) break;
					t = lo + (hi-lo)/2;
					ll type2;
					if(type2=fits(H, M, n, t)){
						if(type == type2){
							lo = t+1;
						}else{
							hi = t;
						}
					}else{
						hi = t;
					}
				}
				// cout << "At " << t << " time it will be destroyed" << endl;
				vi.push_back({0,t-1});
				ll t2=0;
				lo = t, hi = (ll)pow(10,9);
				if (!fits(H,M,n,hi)){
					// do nothing
				}else{

					while(lo <= hi){
						if (t2 == lo+(hi-lo)/2) break;
						t2 = lo+(hi-lo)/2;
						if (fits(H,M,n,t2)){
							hi = t2;
						}else{
							lo = t2+1;
						}
					}
					// cout << "At time " << t2 << " it will be rebuilt again" << endl;
					vi.push_back({t2, inf});
				}
			}
			if (vi.size() == 2){
				cout << 1 << endl;
				pii fst = vi[0];
				pii scnd = vi[1];
				if (fst.second+1 == scnd.first){
					cout << fst.first << " ";
					if (scnd.second == inf) cout << "Inf" << endl;
					else cout << scnd.second << endl;
				}else{
					cout << fst.first << " " << fst.second << endl;
					if (scnd.second == inf) cout << scnd.first << " Inf" << endl;
					else cout << scnd.first << " " << scnd.second << endl;
				}
			}else{
				cout << vi.size() << endl;
				for (pii x: vi){
					cout << x.first << " ";
					if (x.second == inf) cout << "Inf" << endl;
					else{
						cout << x.second << endl;
					}
				}
			}
			// cout << vi.size() << endl;
			// for (pii x: vi){
			// 	cout << x.first << " ";
			// 	if (x.second == inf) cout << "Inf" << endl;
			// 	else cout << x.second<< endl;
			// }
		}else{
			// cout << "Sequence is not zigzag" << endl;
			vector<pii> vi;
			// Let's check how much time will it take to become a LGLGL... type zig zag
			// cout << "Checking for LGLGL... type ";
			ll wait[n];
			fill_n(wait, n, 0ll);
			for (int i = 1; i < n; i += 2){
				if(i < n-1){
					if (H[i] > H[i+1]){
						wait[i] = 0;
					}else{
						if (M[i] <= M[i+1]){
							wait[i] = inf;
						}else{
							ll t=0, hi = pow(10,9), lo = 0ll;
							while (lo <= hi){
								if (t == (lo+(hi-lo)/2)) break;
								t = lo + (hi-lo)/2;
								if(H[i]+M[i]*t <= H[i+1]+M[i+1]*t){
									lo = t+1;
								}else{
									hi = t;
								}
							}
							wait[i] = t;
						}
					}
				}
				if (H[i] > H[i-1]){
					// do nothing
				}else{
					if(M[i] <= M[i-1]){
						wait[i] = inf;
					}else{
						ll t=0, hi = pow(10,9), lo = 0ll;
						while(lo <= hi){
							if (t == (lo+(hi-lo)/2)) break;
							t = lo + (hi-lo)/2;
							if (H[i]+M[i]*t <= H[i-1]+M[i-1]*t){
								lo = t+1;
							}else{
								hi = t;
							}
						}
						wait[i] = max(wait[i], t);
					}
				}
			}
			ll start = *max_element(wait, wait+n);
			// cout << "Start time is " << start << endl;
			if(fits(H, M, n, start)){
				if (start == inf){
					// no intervals here
				}else{
					// starting point is start, and now we need to find the end point
					ll hi = (ll)pow(10,9), lo = 0ll, t=0;
					if (fits(H, M, n, hi)){
						vi.push_back({start, inf});
					}else{
						while(lo <= hi){
							if (t == lo + (hi-lo)/2)break;
							t = lo + (hi-lo)/2;
							if(fits(H, M, n, t)){
								lo = t+1;
							}else{
								hi = t;
							}
						}
						vi.push_back({start, t-1});
					}
				}
			}else{
				// cout << "No intervals found" << endl;
			}
			if (vi.size() == 1 and vi[0].second == -1){
				vi.clear();
			}
			

			// Let's check how much time will it take to become a GLGLG... type zig zag
			fill_n(wait, n, 0ll);
			for (int i = 1; i < n; i +=2 ){
				if (i < n-1){
					if(H[i] < H[i+1]){
						wait[i] = 0;
					}else{
						if(M[i] >= M[i+1]){
							wait[i] = inf;
						}else{
							ll t = 0, hi = pow(10,9), lo = 0ll;
							while(lo <= hi){
								if (t == (lo+(hi-lo)/2)) break;
								t = lo+(hi-lo)/2;
								if (H[i]+M[i]*t >= H[i+1]+M[i+1]*t){
									lo = t+1;
								}else{
									hi = t;
								}
							}
							wait[i] = t;
						}
					}
				}
				if (H[i] < H[i-1]){
					// do nothing
				}else{
					if(M[i] >= M[i-1]){
						wait[i] = inf;
					}else{
						ll t = 0, hi = pow(10, 9), lo = 0ll;
						while(lo <= hi){
							if (t == (lo+(hi-lo)/2)) break;
							t = lo+(hi-lo)/2;
							if (H[i]+M[i]*t >= H[i-1]+M[i-1]*t){
								lo = t+1;
							}else{
								hi = t;
							}
						}
						wait[i] = t;
					}
				}
			}
			start = *max_element(wait, wait+n);
			if (fits(H, M, n, start)){

				if (start == inf){
					// no intervals here 
				}else{
					// starting poit is start, and need to find the end point
					ll hi = (ll)pow(10,9), lo = 0ll, t = 0;
					if (fits(H, M, n, hi)){
						vi.push_back({start, inf});
					}else{
						while(lo <= hi){
							if (t == (lo+(hi-lo)/2))break;
							t = lo + (hi-lo)/2;
							if (fits(H, M, n, t)){
								lo = t+1;
							}else{
								hi = t;
							}
						}
						vi.push_back({start, t-1});
					}
				}
			}else{
				// cout << "No intervals found" << endl;
			}

			if (vi.size() == 0){
				cout << 0 << endl;
			}else{
				if (vi.size() == 1 and vi[0].second == -1){
					vi.clear();
					cout << 0 << endl;
				}else{
					
					cout << vi.size() << endl;
					for (pii x: vi){
						cout << x.first << " ";
						if (x.second == inf) cout << "Inf" << endl;
						else cout << x.second << endl;
					}
				}
			}
		}

	}
}

