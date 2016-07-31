#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool allnegative(int a[], int n){
	for (int i = 0; i < n; i += 1){
		if (a[i] > 0) return false;
	}
	return true;
}

void Print(vector<int> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		if(allnegative(a, n)){
			cout << *max_element(a,a+n) << endl;
		}else{
			vector<int> b;
			int cur=0;
			for (int i = 0; i < n; i += 1){
				if (a[i] < 0){
					if (cur != 0) b.push_back(cur);
					cur = 0;
					b.push_back(a[i]);
				}else{
					cur += a[i];
				}
			}
			if (cur != 0) b.push_back(cur);

			
		}

	}
}