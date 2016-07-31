#include <cstdio>

using namespace std;

int main(void){
	int n, k, t;
	scanf("%d %d", &n, &k);
	int count = 0;
	for (int i = 0; i < n; i += 1){
		scanf("%d", &t);
		if(t%k == 0) count += 1;
	}
	printf("%d\n", count);
}