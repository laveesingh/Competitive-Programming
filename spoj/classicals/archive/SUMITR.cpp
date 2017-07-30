#include <cstdio>
#include <algorithm>
using namespace std;
int a[21][21];

int main(){
	int t, n, r, i, j;
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
			a[i][j] = 0;
			for(j=1;j<=i;j++)
				a[i][j]+= max(a[i-1][j], a[i-1][j-1]);
		}
		for (i=0;i<21;i++){
			for(j=0;j<21;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		r = a[n][1];
		for(i=2;i<=n;i++)
			r=max(r,a[n][i]);
		printf("%d",r);
	}

}