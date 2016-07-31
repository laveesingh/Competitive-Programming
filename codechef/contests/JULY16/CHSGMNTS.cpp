#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define limit 1000000001
#define len(a) (&a)[1]-a
#define init(a, n) a.find(n) != a.end()

void print(vector<int> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}
int totaldist(int n){
	int ans = 0;
	int m, b;
	for(int i = 0; i < n-1; i += 1){
		m = i+1;
		b = (n-m);
		b = (b*(b+1))/2;
		ans += b*m;
	}
	return ans;
}
 
bool isdistinct(int a[], int n){
	for(int i = 0; i < n; i += 1){
		if(count(a, a+n, a[i]) > 1) return false;
	}
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i += 1){
			cin >> arr[i];
		}
		if(isdistinct(arr, n)){
			cout << totaldist(n) << endl;
			continue;
		}
		int count = 0;
		for (int a = 0; a < n-1; a +=1){
			set<int> table;
			for(int b = a; b < n-1; b += 1){
				table.insert(arr[b]);
				vector<int> ind;
				for(int i = b+1; i < n; i +=1){
					if(init(table, arr[i])){
						ind.push_back(i);
					}
				}
				vector<int> lengths;
				int s = b+1;
				int e = n-1;
				if(ind.empty()){
					lengths.push_back(e-s+1);
				} else {
					lengths.push_back(ind.front()-s);
					lengths.push_back(e-ind.back());
					for (int i = 0; i < ind.size()-1; i += 1){
						lengths.push_back(ind[i+1]-ind[i]-1);
					}
				}
				for(int l : lengths){
					count += (l*(l+1))/2;
				}
			}
		}
		cout << count << endl;
	}
}
