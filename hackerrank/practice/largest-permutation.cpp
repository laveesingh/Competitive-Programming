#include <iostream>
#include <map>

using namespace std;

void solve(int a[], int n, int k){
	map<int, int> ind;
	for (int i = 0; i < n; i += 1){
		ind[a[i]] = i;
	}
	int swaps = 0;
	int max = n;
	int curi = 0;
	while (k > 0 && max > 1 && curi < n){
		int maxindex = ind[max];
		int temp;
		if (maxindex == curi) k += 1;
		temp = a[curi];
		a[curi] = a[maxindex];
		a[maxindex] = temp;
		ind[max] = curi;
		swaps += 1;
		ind[a[maxindex]] = maxindex;
		k -= 1;
		max -= 1;
		curi += 1;
	}
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
	// cout << "Total " << swaps << " swaps made." << endl;
}
int main(void){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i] ;
	}
	solve(a, n, k);
}
