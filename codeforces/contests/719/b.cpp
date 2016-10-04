
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front


int main(void){
	// input taking starts here
	int n;
	cin >> n;
	string a;
	cin >> a;

	// input taking ends here

	// solution starts here

	int f = 0, s = 0;
	for(int i = 0; i < n; i += 1){
		if (i%2 and a[i] != 'r'){
			f += 1;
		}
		if (i%2 == 0 and a[i] != 'b'){
			s += 1;
		}
	}
	int first = min(f, s) + abs(f-s)/2;
	f = 0, s = 0;
	for(int i = 0; i < n; i += 1){
		if(i%2 and a[i] != 'b'){
			f += 1;
		}
		if(i%2 == 0 and a[i] != 'r'){
			s += 1;
		}
	}
	int second = min(f, s) + abs(f-s)/2;
	cout << min(first, second) << endl;

	// solution ends here.
}
