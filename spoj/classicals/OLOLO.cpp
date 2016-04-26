
#include <cstdio>

using namespace std;	

int main(void){
	int t, n;
	scanf("%d", &t);
	int ans = 0;
	while (t--){
		scanf("%d", &n);
		ans ^= n;
	}
	printf("%d\n",ans);
}