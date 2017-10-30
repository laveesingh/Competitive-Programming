#include <iostream>
#include <cstdio>


using namespace std;

void Print(int a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	int n, m, ind;
	char chr;
	// cin >> n >> m;
	scanf("%d %d", &n, &m);
	string a;
	char temp[n+1];
	scanf("%s", temp);
	a = temp;
	// cin >> a;
	int lps[n];
	int total = 0;
	lps[0] = 0;
	for (int i = 1; i < n; i += 1){
		if (a[i] == '.' and a[i-1] == '.'){
			lps[i] = lps[i-1]+1;
		}else{
			total += lps[i-1];
			lps[i] = 0;
		}
	}
	total += lps[n-1];
	// cout << "Total:" << total << endl;
	// Print(lps, n);
	for (int q = 0; q < m; q += 1){
		// cin >> ind >> chr;
		scanf("%d %c", &ind, &chr);
		ind -= 1;
		int i = ind;
		int diff = 0,j;
		if (chr != '.'){
			if (a[ind] != '.'){
				// Do nothing here
				// cout << total << endl;
				printf("%d\n", total);
			}else{
				diff += i>0 ? lps[i-1] : 0;
				j = i +1;
				// lps[i] = 0;
				int v = 0;
				while (j<n && a[j] == '.'){
					j += 1;
				}
				int prev = lps[j-1];
				lps[i] = 0;
				j = i+1;
				while (j<n && a[j] == '.'){
					lps[j++] = v++;
				}
				diff += v > 0 ? v-1: 0;
				// cout << " total: " << total << " diff: " << diff << " prev: " << prev << endl;
				total = total + diff - prev;
				// cout << total << endl;
				printf("%d\n", total);
			}
		}else{
			 i = ind;
			if(a[ind] != '.'){
				int v = 1;
				if (a[ind-1] == '.'){
					diff = i>0 ? lps[i-1] : 0;
					lps[i] = diff+1;
				}else{
					lps[i] = 0;
				}
				if (a[ind+1] == '.'){
					j = i+1;
					while(j < n && a[j] == '.'){
						j += 1;
					}
					diff += lps[j-1];
					v = lps[i]+1;
					j = i+1;
					while (j<n && a[j]=='.'){
						lps[j++] = v++;
					}
					total = total - diff + v-1;
					// cout << total << endl;
					printf("%d\n", total);
				}else{
					total = total - diff + lps[i];
					// cout << total << endl;
					printf("%d\n",total);
				}
				
			}else{
				// cout << total << endl;
				printf("%d\n",total);
			}

		}
		a[ind] = chr;
		// cout << "a: " << a << endl;
		// cout << "LPS: ";
		// Print(lps, n);
	}
}