#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int arr[N], n;

inline int partition(int lo, int hi){
	int pivot = arr[hi];
	int i = lo;
	for(int j = lo; j < hi; j++){
		if(pivot >= arr[j]){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[hi], arr[i]);
	return i;
}

void quicksort(int lo, int hi){
	if(lo < hi){
		int pi = partition(lo, hi);
		quicksort(lo, pi-1);
		quicksort(pi+1, hi);
	}
}

int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> arr[i];
//	quicksort(0, n-1);
	sort(arr, arr+n);
	for(int i = 0; i < n; i += 1) cout << arr[i] << " ";
	cout << endl;
}
