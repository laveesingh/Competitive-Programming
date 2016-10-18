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
const int SIZE = 30001;

class node{
public:
	int val;
	bool bal;
};

node T[4*SIZE];
char* a;

void build(int node, int st, int en){
	if(st == en){
		T[node].val = a[st]=='(' ? 1 : -1;
		T[node].bal = true;
		return;
	}
	int mid = (st+en)/2;
	build(2*node, st, mid);
	build(2*node+1, mid+1, en);
	T[node].val = T[2*node].val + T[2*node+1].val;
	if(!T[2*node].bal or !T[2*node+1].bal) T[node].bal = false;
	else if(T[2*node].val < T[2*node+1].val) T[node].bal = false;
	else T[node].bal = true;
}

void update(int node, int st, int en, int i){
	if(st == en){
		T[node].val = -T[node].val;
		return;
	}
	int mid = (st+en)/2;
	if(i <= mid) update(2*node, st, mid, i);
	else update(2*node+1, mid+1, en, i);
	T[node].val = T[2*node].val + T[2*node+1].val;
	if(!T[2*node].bal or !T[2*node+1].bal) T[node].bal = false;
	else if(T[2*node].val < T[2*node+1].val) T[node].bal = false;
	else T[node].bal = true;
}

int main(void){
	ios::sync_with_stdio(false);
	for(int cc = 0; cc < 10; cc++){
		int n, m,i;
		printf("Test %d:\n",cc+1);
		scanf("%d",&n);	
		a = new char[n];
		scanf("%s", a);
		build(1, 0, n-1);
		scanf("%d", &m);
//		for(int i = 1; i < 8; i += 1)
//			cout << T[i].val<<"("<<T[i].bal<<")" << "  ";
//		cout << endl;	
		for(int _ = 0; _ < m; _++){
			scanf("%d", &i);
			if(i == 0){
				if(T[1].bal and T[1].val==0) printf("YES\n");
				else printf("NO\n");
			}else{
				update(1, 0, n-1, i-1);
			}
//		for(int i = 1; i < 8; i += 1)
//			cout << T[i].val<<"("<<T[i].bal<<")" << "  ";
//		cout << endl;	

		}
	}
}

