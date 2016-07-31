#include <cstdio>
#include <iostream>

using namespace std;

#define sc(x) scanf("%d", &x)

int n, q, *a;

int parent(int i){
	if (i != a[i]){
		// cout << "Finding parent of i = " << i << endl;
		a[i] = parent(a[i]);
	}
	// cout << "For i = " << i << " Parent " << a[i] << "Found" << endl;
	return a[i];
}

void set_parent_1(int x){
	int i = parent(x);
	a[x] = x;
	a[i] = x;
}

void set_parent_2(int x, int y){
	int i = parent(x);
	int j = parent(y);
	a[i] = j;
}

int main(void){
	int type, x, y;
	sc(n);
	sc(q);
	a = new int[n];
	for (int i = 0; i < n; i += 1){
		a[i] = i;
	}

	for(int i = 0; i < q; i += 1){
		sc(type);
		if (type == 1){
			sc(x);
			sc(y);
			x -= 1;
			y -= 1;
			set_parent_2(x, y);
		} else if(type == 2){
			sc(x);
			x -= 1;
			set_parent_1(x);
		} else {
			sc(x);
			x -= 1;
			printf("%d\n", parent(x)+1);
		}
		// printf("Here is here is the array: ");
		// for (int i = 0; i < n; i += 1){
		// 	printf("%d ", a[i]);
		// }
		// printf("\n");
	}
}