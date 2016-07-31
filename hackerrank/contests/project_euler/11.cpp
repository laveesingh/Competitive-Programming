#include <cstdio>
#include <algorithm>

using namespace std;

#define sc(n) scanf("%d", &n)
#define F(i,n) for (int i = 0; i < n; i += 1)

int a[20][20];


int main(void){
	F(i,20) 
		F(j,20)
			sc(a[i][j]);
	int maxans = 1;
	F(i,17){
		F(j,17){
			int ans = 1;
			F(k,4){
				ans *= a[i+k][j];
			}
			maxans = max(ans, maxans);
			ans = 1;
			F(k,4){
				ans *= a[i][j+k];
			}
			maxans = max(maxans, ans);
			ans = 1;
			F(k,4){
				ans *= a[i+k][j+k];
			}
			maxans = max(maxans, ans);
			ans = 1;
			F(k,4){
				ans *= a[i+k][j+4-k];
			}
			maxans = max(maxans, ans);
		}
	}
	for (int i = 17; i < 20; i += 1){
		for (int j = 0; j < 17; j += 1){
			int ans = 1;
			F(k, 4){
				ans *= a[i][j+k];
			}
			maxans = max(ans, maxans);
		}
	}
	for (int i = 0; i < 17; i += 1){
		for (int j = 17; j < 20; j += 1){
			int ans = 1;
			F(k,4){
				ans *= a[i+k][j];
			}
			maxans = max(ans, maxans);
		}
	}
	printf("%d\n", maxans);
}