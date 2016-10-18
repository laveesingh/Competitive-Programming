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
const int SIZE=1000001;
int isprime[SIZE];

void sieve(){
	isprime[0] = isprime[1] = 1;
	for(int i = 4; i < SIZE; i += 2){
		isprime[i] = 1;
	}
	for(int i = 3; i < sqrt(SIZE)+1.5; i += 2){
		if(!isprime[i]){
			for(int j = i*i; j < SIZE; j += 2*i){
				isprime[j] = 1;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	sieve();
	for(int i = 0; i < 100; i += 1){
		if(!isprime[i]) cout << i << endl;
	}
}

