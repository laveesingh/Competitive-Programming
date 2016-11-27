#include <bits/stdc++.h>

using namespace std;

const int N = 50001;
char str[N];
int Rank[N], pos[N]; // pos contains the suffix array
int cnt[N], Next[N];
bool bh[N], b2h[N];
int lcp[N]; // lcp[i] => lcp(pos[i], pos[i-1])

bool comp_int(int a, int b){
	return str[a] < str[b];
}

inline void buildSA(int n){
	for(int i=0; i<n; i++)
		pos[i] = i;
	sort(pos, pos+n, comp_int);
	for(int i=0; i<n;i++){
		bh[i] = i==0 || str[pos[i]] != str[pos[i-1]];
		b2h[i] = false;
	}
	for(int h=1; h<n; h<<=1){
		int buckets = 0;
		for(int i=0, j; i<n; i=j){
			j = i+1;
			while (j<n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
		}
		if(buckets == n) break;
		for(int i=0; i<n; i=Next[i]){
			cnt[i] = 0;
			for(int j=i; j<Next[i]; j++) Rank[pos[j]] = i;
		}
		cnt[Rank[n-h]]++;

		b2h[Rank[n-h]] = true;
		for(int i=0; i<n; i=Next[i]){
			for(int j=i; j<Next[i]; j++){
				int s = pos[j] - h;
				if(s >= 0){
					int head = Rank[s];
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
				}
			}
			for(int j=i; j<Next[i]; j++){
				int s = pos[j] - h;
				if (s >= 0 and b2h[Rank[s]]){
					for(int k=Rank[s]+1; !bh[k]&&b2h[k]; k++)
						b2h[k] = false;
				}
			}
		}
		for(int i=0; i<n; i++){
			pos[Rank[i]] = i;
			bh[i] |= b2h[i];

		}
	}
	for(int i=0; i<n; i++)
		Rank[pos[i]] = i;
}

inline void buildLCP(int n){
	for(int i=0; i<n; i++) Rank[pos[i]] = i;
	lcp[0] = 0;
	for(int i=0, h=0; i<n; i++){
		if(Rank[i] > 0){
			int j = pos[Rank[i]-1];
			while (i+h < n && j+h <n && str[i+h] == str[j+h]) h++;
			lcp[Rank[i]] = h;
			if(h > 0) h--;
		}
	}
}

int main(void){
	int n, t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i += 1) cin >> str[i];
		buildSA(n);
		buildLCP(n);
		int curConseq = 0, maxConseq = 0;
		for(int i = 1; i < n; i += 1){
			if(abs(pos[i] - pos[i-1]) <= lcp[i]){
				curConseq++;
				maxConseq = max(curConseq, maxConseq);
			}else{
				curConseq = 0;
			}
		}
		cout << maxConseq+1 << endl;
	}
}
