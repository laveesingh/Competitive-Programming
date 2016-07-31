#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(void){
	int n, max;
	// cin >> n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i += 1){
		// cin >> a[i];
		scanf("%d",&a[i]);
	}
	// map<int, int> f;
	int f[n+1];
	fill_n(f,n+1,0);
	// map<int, int> ind;
	// map<int, int> vis;
	// for (int i = 0; i < n; i += 1){
	// 	if (vis[a[i]]){
	// 		// Do nothing
	// 	}else{
	// 		ind[a[i]] = i;
	// 		vis[a[i]] = 1;
	// 	}
	// }
	// for (map<int, int>::const_iterator it = ind.begin(); it != ind.end(); it++){
	// 	cout << it -> first << " " << it -> second << endl;;
	// }

	for (int i = 0; i < n; i += 1){
		// map <int, int> d;
		int d[n+1];
		fill_n(d,n+1,0);
		for (int j = i; j < n; j += 1){
			if (i == j){
				// cout << "First: i:"<<i<<" j:"<<j<<" belongs to "<<a[j]<<endl;
				f[a[j]] += 1;
				d[a[j]] = 1;
				max = a[j];
			}else{
				d[a[j]] +=  1;
				if (d[a[j]] > d[max]) max = a[j];
				// cout << "a[j]:"<<a[j]<<" max:"<<max<<" ind[a[j]]:"<<ind[a[j]]<<" ind[max]:"<<ind[max] << endl;
				if (d[a[j]] == d[max]){
					// cout << "Second first: i:"<<i<<"j:"<<j<<" belongs to ";
					if (max == a[j]){
						f[a[j]] += 1;
						// cout << a[j] << endl;
					}
					// else if (ind[a[j]] < ind[max]){
					else if(a[j] < max){
						f[a[j]] += 1;
						max = a[j];
						// cout << a[j] << endl;
					}else{
						f[max] += 1;
						// cout << max << endl;
					}
				}else if (d[a[j]] > d[max]){
					// cout << "Third i:"<<i<<" j:"<<j<<" belongs to "<<a[j]<<endl;
					f[a[j]] += 1;
					max = a[j];
				}else{
					// cout << "Fourth i:"<<i<<" j:"<<j<<" belongs to "<<max<< endl;
					f[max] += 1;
				}
			}
		}
	}
	// for (map<int,int>::const_iterator it = f.begin(); it != f.end(); it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	for (int i = 1; i <=n; i += 1){
		// cout << f[i] << " ";
		printf("%d ",f[i]);
	}
	// cout << endl;
	printf("\n");
}