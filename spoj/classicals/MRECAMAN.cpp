#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<pii, int> piii;
typedef map<int, int> mii;
typedef deque<int> di;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<pll, ll> plll;
typedef map<ll, ll> mll;
typedef deque<ll> dl;

#define F(i, n) for(ll i = 0; i < n; i += 1)
#define PRINT(a,n) for(ll i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(ll i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()
#define Front(a) *(a.begin())
#define Back(a) *(a.rbegin())
#define Index(a, x) a.find(x) - a.begin()

const int inf = INT_MAX;
const int SIZE = 500001;
int seq[SIZE];
set<int> sseq;

inline void Set(){
	seq[0] = 0;
	sseq.insert(0);
	for(int i = 1; i < SIZE; i += 1){
		if(seq[i-1] -i > 0 and init(sseq, seq[i-1]-i) == false){
			seq[i] = seq[i-1]-i;
			sseq.insert(seq[i]);
		}else{
			seq[i] = seq[i-1]+i;
			sseq.insert(seq[i]);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	Set();
	int n;
	while(true){
		cin >> n;
		if (n == -1) break;
		cout << seq[n] << endl;
	}
}

