#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int sum = accumulate(a, a+n, 0);
	int x = 3 * (n*(n-1))/2;
	if((sum - x) % n == 0){
		int init = (sum-x)/n;
		int b[n], pos = 0, neg = 0;
		for (int i = 0; i < n; i += 1){
			b[i] = init + 3*i;
		}
		for (int i = 0; i < n; i += 1){
			if (a[i] < b[i]){
				neg++;
			}else if(a[i] > b[i]){
				pos++;
			}	
		}
		cout << "Yes " << max(neg, pos) << endl;
	}else{
		cout << "No" << endl;
	}
}