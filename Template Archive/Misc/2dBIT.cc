#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 1025;
int BIT[N][N], mat[N][N];
int n;

inline void update(int x, int y, int val){ // here val is value how much we need to increase to set it to required
	int fy = y;
	for(; x <= n; x += (x & -x)){
		y = fy;
		for(; y <= n; y += (y & -y))
			BIT[x][y] += val;
	}
}

inline int getSum(int x, int y){
	int sum = 0;
	int fy = y;
	for(; x > 0; x -= (x&-x)){
		y = fy;
		for(; y > 0; y-= (y&-y))
			sum += BIT[x][y];
	}
	return sum;
}

inline int query(int x1, int y1, int x2, int y2){
	return getSum(x2, y2) - getSum(x2, y1-1)
			-  getSum(x1-1, y2) + getSum(x1-1, y1-1);
}

int main(void){
	int t, x1, x2, y1, y2, val, inc;
	char type[4];
	iint(t);
	while(t--){
		iint(n);
		memset(BIT, 0, sizeof(BIT));
		memset(mat, 0, sizeof(mat));
		while(1){
			istr(type);
			if(type[1] == 'N') break;
			if(type[1] == 'E'){
				iint(x1); iint(y1); iint(val);
				x1++; y1++;
				inc = val - mat[x1][y1];
				mat[x1][y1] = val;
				update(x1, y1, inc);
			}else{
				iint(x1); iint(y1); iint(x2); iint(y2);
				x1++; y1++; x2++; y2++;
				oint(query(x1, y1, x2, y2));
			}
		}
		printf("\n");
	}
}
