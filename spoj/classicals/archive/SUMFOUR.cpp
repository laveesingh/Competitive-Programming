/*input
3 
0 0 0 0 
0 0 0 0 
-1 -1 1 1
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
	// cout << "Here's the ab array: " << endl;
	// for (int i = 0; i < n*n; i+= 1){
	// 	cout << ab[i] << " ";
	// }
	// cout << endl;

	vector<int> cd(n*n);
	k = 0;
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			cd[k++] = c[i]+d[j];
		}
	}
	sort(cd.begin(), cd.end());
	// cout << "Here's the cd array: " << endl;
	// for (int i = 0; i < n*n; i += 1){
	// 	cout << cd[i] << " ";
	// }
	// cout << endl;

	int count = 0;
	int i = 0, j = (n*n)-1;
	while (i < n*n and j >= 0){
		// cout << "Stuck in while" << i << " " << j << endl;
		if (ab[i]+cd[j] > 0){
			// cout << "F" << endl;
			j--;
		}else if(ab[i]+cd[j] < 0){
			// cout << "S" << endl;
			i++;
		}else{
			x = 1, y = 1;
			i++;
			j--;
			while(i < n*n and ab[i] == ab[i-1]){
				i++;
				x++;
			}
			while (j >= 0 and cd[j] == cd[j+1]){
				j--;
				y++;
			}
			count += x*y;
		}
	}
	cout << count << endl;
}