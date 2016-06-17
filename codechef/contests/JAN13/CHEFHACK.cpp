#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
// #include <string.h>

using namespace std;

#define limit 10000001

#define input(a,n) for(int i = 0; i < n; i += 1) scanf("%d", &a[i]);
#define isvalid(i,j,n) (i>=0&&i<n&&j>=0&&j<n)


int isprime[limit];
int howmanyprimes[limit];
int **a,**visited;
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};

void set_primes(){
	fill_n(isprime, limit, 1);
	isprime[0] = 0;
	isprime[1] = 0;
	
	for(int i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < sqrt(limit)+1; i += 2){
		if(isprime[i]){
			for(int j = i*i; j < limit; j += i){
				isprime[j] = 0;
			}
		}
	}
	howmanyprimes[0] = howmanyprimes[1] = 0;
	howmanyprimes[2] = 0;
	for (int i = 3; i < limit; i += 1){
		howmanyprimes[i] = howmanyprimes[i-1]+isprime[i];
	}
}

void bfs(int i, int j,int n){
	// cout << "Doing bfs for: " << i  << " " << j << endl;
	visited[i][j] = 1;
	for (int k = 0; k < 4; k += 1){
		if(isvalid(i+X[k],j+Y[k],n) && !(visited[i+X[k]][j+Y[k]])&& (a[i+X[k]][j+Y[k]]%2 == a[i][j]%2) && !(isprime[a[i+X[k]][j+Y[k]]])){
			// cout << a[i+X[k]][j+Y[k]] << " is equal in parity to " << a[i][j] << endl; 
			bfs(i+X[k], j+Y[k], n);
		}	
	}
}

int main(void){
	set_primes();
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = new int*[n];
		visited = new int*[n];
		for (int j = 0; j < n; j += 1){
			a[j] = new int[n];
			visited[j] = new int[n];
			fill_n(visited[j], n, 0);
			input(a[j],n);
		}
		int wtries = 0;
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < n; j += 1){
				if(!visited[i][j]){
					if(isprime[a[i][j]]){
						int toincrease = howmanyprimes[a[i][j]];
						// cout << "Increased " << toincrease <<" at " << i << " " << j << endl;
						wtries += toincrease;
					}else{
						int toincrease = (a[i][j]%2 ? (a[i][j]+3)/2 : a[i][j]/2);
						// cout << "Increased " << toincrease <<" at " << i << " " << j << endl;
						wtries += toincrease;
						bfs(i,j,n);
					}
				}
			}
		}		
		printf("%d\n", wtries);
	}

}

// def case():
// 	n = randint(1,5)
// 	print n
// 	for i in xrange(n):
// 		for j in xrange(n):
// 			print randint(0,10),
// 		print
// 	