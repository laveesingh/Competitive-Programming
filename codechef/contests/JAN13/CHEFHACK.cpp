#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int limit = 10000001;
int isprime[limit];
int dpprime[limit];
int **a, **visited;

#define sc(n) scanf("%d", &n)
#define F(i,n) for(int i = 0; i < n; i += 1)
#define even(n)  (!isprime[n] && n%2 == 0)
#define odd(n)  (!isprime[n] && !even(n))
#define ustries(n) (isprime[n] ? dpprime[n]-1 : (even(n) ? n/2 : (n+3)/2))

void sieve(){
	fill_n(isprime, limit, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < sqrt(limit)+1; i += 2){
		if (isprime[i]){
			for(int j = i*i; j < limit; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	dpprime[0]=dpprime[1] = 0;
	for (int i = 2; i < limit; i += 1){
		dpprime[i] = isprime[i] ? dpprime[i-1]+1 : dpprime[i-1];
	}
}

void dfs(int i, int j){

}

int main(void){
	sieve();
	int t;
	sc(t);
	while(t--){
		int n;
		sc(n);
		a = new int*[n];
		visited = new int*[n];
		F(i,n) {
			a[i] = new int[n];
			visited[i] = new int[n];
		}
		F(i,n) F(j,n) sc(a[i][j]);
		long long ans = 0;
		F(i,n){
			F(j,n){
				if(!visited[i][j]){
					visited[i][j] = 1;
					ans += ustries(a[i][j]);
					dfs(i,j);
				}
			}
		}
	}
}