#include <map>
#include <cstdio>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		// int a[n];
		int temp;
		map<int, int> freq;
		for (int i = 0; i< n; i += 1){
			scanf("%d", &temp);
			freq[temp] += 1;
		}
		bool done = false;
		for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
			if(it->second > n/2){
				printf("YES %d\n", it->first);
				done =true;
				break;
			}
		}
		if(done == true){
			continue;
		}else{
			printf("NO\n");
		}
	}
}