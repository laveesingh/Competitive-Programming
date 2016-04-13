#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

class activity{
public:
	int start, end, comp;
	activity(){}
	activity(int s, int e, int c){
		start = s;
		end = e;
		comp = c;
	}
};

bool compare(activity act1, activity act2){
	if (act1.end == act2.end){
		return act1.start < act2.start ? true : false;
	}
	return act1.end < act2.end ? true : false;
}

int solve(int n, int k, activity a[]){
	int ans = 0;
	sort(a, a+n, compare);
	map<int, int> d;
	for(int i = 0; i < n;i += 1){
		activity act = a[i];
		if (d[act.comp] == 0){
			d[act.comp] = act.end;
			ans += 1;
		}else{
			if (act.start >= d[act.comp]){
				ans += 1;
				d[act.comp] = act.end;
			}
		}
	}
	return ans;
}

int main(void){
	int t, n, k, x, y, z;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d", &n, &k);
		activity a[n];
		for (int i = 0; i < n; i+=1){
			scanf("%d %d %d", &x, &y, &z);
			a[i] = activity(x, y, z);
		}
		printf("%d\n",solve(n, k, a));
	}
}