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
const int SIZE = 100001;
int Ttree[4*SIZE], Ftree[4*SIZE], TLtree[4*SIZE], FLtree[4*SIZE], stTree2[4*SIZE], stTree5[4*SIZE];
int Array[SIZE], n, m, twos, fives;
int DPT[SIZE], DPF[SIZE];

// Function below gives power of 2 in number n
inline int Tfact(int n){
	int cnt = 0;
	while(n%2 == 0){
		cnt++;
		n /= 2;
	}
	return cnt;
}

//Function below gives power of 5 in number n
inline int Ffact(int n){
	int cnt = 0;
	while(n%5 == 0){
		cnt++;
		n /= 5;
	}
	return cnt;
}

// create prefix-sum for powers of 2 and 5 for all numbers till SIZE
inline void setDP2(){
	DPT[1] = 0;
	for(int i = 2; i < SIZE; i += 1){
		DPT[i] = DPT[i-1] + Tfact(i);
	}
}

inline void setDP5(){
	DPF[1] = 0;
	for(int i = 2; i < SIZE; i += 1){
		DPF[i] = DPF[i-1] + Ffact(i);
	}
}

// Building of segment tree starts here
void build2(int node, int st, int en){
	if (st == en){
		Ttree[node] = Tfact(Array[st]);
	}else{
		int mid = (st+en)/2;
		build2(2*node, st, mid);
		build2(2*node+1, mid+1, en);
		Ttree[node] = Ttree[2*node] + Ttree[2*node+1];
	}
}

void build5(int node, int st, int en){
	if (st == en){
		Ftree[node] = Ffact(Array[st]);
	}else{
		int mid = (st+en)/2;
		build5(2*node, st, mid);
		build5(2*node+1, mid+1, en);
		Ftree[node] = Ftree[2*node] + Ftree[2*node+1];
	}
}

// Update operations start here



// propagation function

void delazy2(int node){
	if(node >= 4*SIZE) return;
	TLtree[node] = 0;
	delazy2(2*node);
	delazy2(2*node+1);
}

void delazy5(int node){
	if(node >= 4*SIZE) return;
	FLtree[node] = 0;
	delazy2(2*node);
	delazy2(2*node+1);
}

void propagate2(int node, int st, int en){
	if(TLtree[node] == 0) return;
	if (TLtree[node] != 0){
		Ttree[node] += (en-st+1)*TLtree[node];
		if(st != en){
			TLtree[2*node] += TLtree[node];
			TLtree[2*node+1] += TLtree[node];
		}
		TLtree[node] = 0;
	}
}

void propagate5(int node, int st, int en){
	if(FLtree[node] == 0) return;
	if (FLtree[node] != 0){
		Ftree[node] += (en-st+1)*FLtree[node];
		if(st != en){
			FLtree[2*node] += FLtree[node];
			FLtree[2*node+1] += FLtree[node];
		}
		FLtree[node] = 0;
	}
}

void update2(int node, int st, int en, int i, int j, int start){
	#ifndef DEBUG
		cout << "Update2:" << "st:"<< st << "en:" << en <<"i:" << i << "j:" << j << endl;
	#endif
	if(stTree2[node] != -1){
		int start = st - stTree2[node] + 1;
		int end = en - stTree2[node] + 1;
		Ttree[node] = DPT[end] - DPT[start-1];
		if(st != en){
				stTree2[2*node] = stTree2[node];
				stTree2[2*node+1] = stTree2[node];
		}
		stTree2[node] = -1;
	}
	propagate2(node, st, en);	
	if(st >= i and en <= j){
		int sp = st - start + 1;
		int ep = en - start + 1;
		Ttree[node] = DPT[ep] - DPT[sp-1];
		delazy2(2*node);
		delazy2(2*node+1);
		if(st != en){
			stTree2[2*node] = start;
			stTree2[2*node+1] = start;
		}
		return;
	}
	if (en < i or j < st or i > j or st > en) return;
	int mid = (st+en)/2;
	//if(j <= mid) update2(2*node, st, mid, i, j, start);
	//else if(i > mid) update2(2*node+1, mid+1, en, i, j, start);
	//else{
		update2(2*node, st, mid, i, j, start);
		update2(2*node+1, mid+1, en, i, j, start);
	//}
Ttree[node] = Ttree[2*node] + Ttree[2*node+1];
}

void update5(int node, int st, int en, int i, int j, int start){
	#ifndef DEBUG
		cout << "Update5:" << "st:"<< st << "en:" << en <<"i:" << i << "j:" << j << endl;
	#endif
	if(stTree5[node] != -1){
		int start = st - stTree5[node] + 1;
		int end = en - stTree5[node] + 1;
		Ftree[node] = DPF[end] - DPF[start-1];
		if(st != en){
				stTree5[2*node] = stTree5[node];
				stTree5[2*node+1] = stTree5[node];
		}
		stTree5[node] = -1;
	}
	propagate5(node, st, en);	
	if(st >= i and en <= j){
		int sp = st - start + 1;
		int ep = en - start + 1;
		Ftree[node] = DPF[ep] - DPF[sp-1];
		delazy5(2*node);
		delazy5(2*node+1);
		if(st != en){
			stTree5[2*node] = start;
			stTree5[2*node+1] = start;
		}
		return;
	}
	if (en < i or j < st or i > j or st > en) return;
	int mid = (st+en)/2;
	//if(j <= mid) update5(2*node, st, mid, i, j, start);
	//else if(i > mid) update5(2*node+1, mid+1, en, i, j, start);
	//else{
		update5(2*node, st, mid, i, j, start);
		update5(2*node+1, mid+1, en, i, j, start);
	//}
Ftree[node] = Ftree[2*node] + Ftree[2*node+1];
}

void mult2(int node, int st, int en, int i, int j){
	#ifndef DEBUG
			cout << "Mult2: " << st << " " << en << " " << i << " " << j << " : " ;
	#endif
	if(stTree2[node] != -1){
		int start = st - stTree2[node] + 1;
		int end = en - stTree2[node] + 1;
		Ttree[node] = DPT[end] - DPT[start-1];
		if(st != en){
				stTree2[2*node] = stTree2[node];
				stTree2[2*node+1] = stTree2[node];
		}
		stTree2[node] = -1;
	}
	propagate2(node, st, en);	
	if (st >= i and en <= j){
	#ifndef DEBUG
				cout << "matching matching" << endl;	
	#endif
		Ttree[node] += (en-st+1) * twos;
		if (st != en){
			TLtree[2*node] += twos;
			TLtree[2*node+1] += twos;
		}
		return;
	}
	if (en < i or j < st or j < i or en < st) return;
	
	#ifndef DEBUG
			cout << "propagating below" << endl;
	#endif
	int mid = (st + en)/2;
	//if(j <= mid) mult2(2*node, st, mid, i, j);
	//else if(i > mid) mult2(2*node+1, mid+1, en, i, j);
	//else{
		mult2(2*node, st, mid, i, j);
		mult2(2*node+1, mid+1, en, i, j); 
	//}
	Ttree[node] = Ttree[2*node] + Ttree[2*node+1];
}	

void mult5(int node, int st, int en, int i, int j){
	if(stTree5[node] != -1){
		int start = st - stTree5[node] + 1;
		int end = en - stTree5[node] + 1;
		Ftree[node] = DPF[end] - DPF[start-1];
		if(st != en){
				stTree5[2*node] = stTree5[node];
				stTree5[2*node+1] = stTree5[node];
		}
		stTree5[node] = -1;
	}
	propagate5(node, st, en);	
	if (st >= i and en <= j){
		Ftree[node] += (en-st+1) * fives;
		if (st != en){
			FLtree[2*node] += fives;
			FLtree[2*node+1] += fives;
		}
		return;
	}
	if (en < i or j < st or j < i or en < st) return;
	int mid = (st + en)/2;
	//if(j <= mid) mult5(2*node, st, mid, i, j);
	//else if(i > mid) mult5(2*node+1, mid+1, en, i, j);
	//else{
		mult5(2*node, st, mid, i, j);
		mult5(2*node+1, mid+1, en,i, j);
	//}
Ftree[node] = Ftree[2*node] + Ftree[2*node+1];
}	

// Get queries start here
int get5(int node, int st, int en, int i, int j){
	if(stTree5[node] != -1){
		int start = st - stTree5[node] + 1;
		int end = en - stTree5[node] + 1;
		Ftree[node] = DPF[end] - DPF[start-1];
		if (st != en){
				stTree5[2*node] = stTree5[node];
				stTree5[2*node+1] = stTree5[node];
		}
		stTree5[node] = -1;
	}
	propagate5(node, st, en);	
	int mid = (st+en)/2;
	if (en < i or j < st or j < i or st > en) return 0;
	if(st >= i and en <= j) return Ftree[node];	
	//if(j <= mid)
	//	return get5(2*node, st, mid, i, j);
	//if(i > mid)
	//	return get5(2*node+1, mid+1, en, i, j);
	int lget = get5(2*node, st, mid, i, j);
	int rget = get5(2*node+1, mid+1, en, i, j);
	return lget+rget;
}

int get2(int node, int st, int en, int i, int j){
	if(stTree2[node] != -1){
		int start = st - stTree2[node] + 1;
		int end = en - stTree2[node] + 1;
		Ttree[node] = DPT[end] - DPT[start-1];
		if(st != en){
				stTree2[2*node] = stTree2[node];
				stTree2[2*node+1] = stTree2[node];
		}
		stTree2[node] = -1;
	}
	propagate2(node, st, en);	
	int mid = (st+en)/2;
	if (en < i or j < st or j < i or st > en) return 0;
	if(st >= i and en <= j) return Ttree[node];	
	//if(j <= mid)
	//	return get2(2*node, st, mid, i, j);
	//if(i > mid)
	//	return get2(2*node+1, mid+1, en, i, j);
	int lget = get2(2*node, st, mid, i, j);
	int rget = get2(2*node+1, mid+1, en,i, j);
	return lget+rget;
}


int main(void){
	ios::sync_with_stdio(false);
	setDP5();
	setDP2();
	int t, type, li, ri, Y;
	scanf("%d", &t);	
	while(t--){
		scanf("%d %d", &n, &m);
		fill_n(stTree2, 4*SIZE, -1);
		fill_n(stTree5, 4*SIZE, -1);
		fill_n(TLtree, 4*SIZE, 0);
		fill_n(FLtree, 4*SIZE, 0);
		for(int i = 0; i < n; i += 1) scanf("%d", &Array[i]);
		int answer = 0;
		build2(1, 0, n-1);
		build5(1, 0, n-1);
		#ifdef DEBUG
			cout << "Segtree2: ";
			for(int i = 0; i < 15; i += 1)
				cout << Ttree[i] << " ";
			cout << endl << "Segtree5: ";
			for(int i = 0; i < 15; i += 1)
				cout << Ftree[i] << " ";
			cout << endl;
		#endif	
		for(int qq = 0; qq < m; qq += 1){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d %d %d", &li, &ri, &Y);
				twos = Tfact(Y);
				fives = Ffact(Y);
	#ifndef DEBUG
						cout << "adding twos: " << twos << endl;
	#endif
				if(twos > 0)	mult2(1, 0, n-1, li-1, ri-1);
				if(fives > 0) mult5(1, 0, n-1, li-1, ri-1);				
			}else if(type == 2){
				scanf("%d %d %d", &li, &ri, &Y);
				update2(1, 0, n-1, li-1, ri-1, li-1);
				update5(1, 0, n-1, li-1, ri-1, li-1);
				twos = Tfact(Y);
				fives = Ffact(Y);
				if(twos > 0)	mult2(1, 0, n-1, li-1, ri-1);
				if(fives > 0) mult5(1, 0, n-1, li-1, ri-1);
				#ifndef DEBUG
					cout << "After update2: Seg2: ";for(int i = 0; i < 15; i += 1)	cout << Ttree[i] << " ";cout << endl;
					cout << "After update2: Lazy2: ";for(int i = 0; i < 15; i += 1)	cout << TLtree[i] << " ";cout << endl;
					cout << "After update2: sst2: "; for(int i = 0; i < 15; i += 1) cout << stTree2[i] << " "; cout << endl;
					cout << endl << endl;
				#endif
			}else{
				scanf("%d %d", &li, &ri);
				twos = get2(1, 0, n-1, li-1, ri-1);
				fives = get5(1, 0, n-1, li-1, ri-1);
				answer += min(twos, fives);
			#ifndef DEBUG
					cout << "Query " << li << " " << ri << " " << twos << " " << fives << endl;
			#endif
			}
			#ifdef DEBUG
					cout << "After update2: Seg2: ";for(int i = 0; i < 15; i += 1)	cout << Ttree[i] << " ";cout << endl;
					cout << "After update2: Lazy2: ";for(int i = 0; i < 15; i += 1)	cout << TLtree[i] << " ";cout << endl;
					cout << "After update2: sst2: "; for(int i = 0; i < 15; i += 1) cout << stTree2[i] << " "; cout << endl;
					cout << endl << endl;
			#endif	

		}
		printf("%d\n", answer);
	}
}


