#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define piii pair<pii, int>
#define N 30001
#define BLOCK 200
#define SIZE 1000001

int cnt[SIZE], a[N], Count = 0;
int n;

bool cmp(piii a, piii b){
	if(a.first.first/BLOCK == b.first.first/BLOCK){
		return a.first.second < b.first.second;
	}else{
		return a.first.first < b.first.first;
	}
}

int main(void){
	// ios::sync_with_stdio(false);
	// cin >> n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		// cin >> a[i];
		scanf("%d", &a[i]);
	}
	int q, x, y;
	// cin >> q;
	scanf("%d", &q);
	piii qr[q];
	int ans[q];
	for(int i = 0; i < q; i += 1){
		// cin >> x >> y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		qr[i] = {{x, y}, i};
	}
	sort(qr, qr+q, cmp);
	int curL = 0, curR = 0;
	for(int i = 0; i < q; i += 1){
		piii cur = qr[i];
		int l = cur.first.first;
		int r = cur.first.second;
		// cout << "l: " << l << " r: " << r << endl;
		while(curL <= l){
			cnt[a[curL]]--;
			if(cnt[a[curL]] == 0) Count--;
			curL++;
		}
		while(curL > l){
			cnt[a[curL-1]]++;
			if(cnt[a[curL-1]] == 1) Count++;
			curL--;
		}
		while(curR <= r){
			cnt[a[curR]]++;
			if(cnt[a[curR]] == 1) Count++;
			curR++;
		}
		while(curR > r+1){
			cnt[a[curR-1]]--;
			if(cnt[a[curR-1]] == 0) Count--;
			curR--;
		}
		ans[cur.second] = Count;
		// for(int i = 0; i < 10; i += 1){
		// 	cout << cnt[i] << " " ;
		// }
		// cout << endl;
	}
	for(int i = 0; i < q; i += 1){
		// cout << ans[i] << endl;
		printf("%d\n", ans[i]);
	}
}