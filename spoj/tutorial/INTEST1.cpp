#include <cstdio>

using namespace std;

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int count = 0, x;
	for (int i = 0; i < n; i += 1){
		scanf("%d", &x);
		if (x%k == 0) count++;
	}
	printf("%d\n", count);
}