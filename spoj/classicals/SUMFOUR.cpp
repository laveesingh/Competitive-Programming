/*input
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
*/

#include <bits/stdc++.h>

using namespace std;

#define vli vector<int>::iterator

int main(void){
	ios::sync_with_stdio(false);
	int n, x, y, z, w;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i += 1){
		// cin >> a[i] >> b[i] >> c[i] >> d[i];
		cin >> x >> y >> z >> w;
		a[i] = x;
		b[i] = y;
		c[i] = z;
		d[i] = w;
	}

	vector<int> ab(n*n);
	int k = 0;
	for (int i = 0; i < n; i +=1){
		for (int j = 0; j < n; j += 1){
			ab[k++] = a[i]+b[j];
		}
	}
	sort(ab.begin(), ab.end());

	vector<int> cd(n*n);
	k = 0;
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			cd[k++] = c[i]+d[j];
		}
	}
	sort(cd.begin(), cd.end());

	int count = 0;
	int i = 0, j = (n*n)-1;
	while (i < n*n and j >= 0){
		// cout << "Stuck in while" << i << " " << j << endl;
		if (ab[i]+cd[j] > 0){
			cout << "F" << endl;
			j--;
		}else if(ab[i]+cd[j] < 0){
			cout << "S" << endl;
			i++;
		}else{
			cout << i << ": " << i << "a[i]: " << a[i] << " a[i+1]: " << a[i+1] << endl;
			x = 1, y = 1;
			while(i < (n*n-1) and a[i] == a[i+1]){
				i++;
				x++;
			}
			while(j >= 1 and b[j] == b[j-1]){
				j--;
				y++;
			}
			count += x*y;
		}
	}
	cout << count << endl;
}