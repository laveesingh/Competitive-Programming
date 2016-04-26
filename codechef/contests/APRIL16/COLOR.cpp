#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b, int c){
	if (a >= b && a >= c){
		return a;
	}else{
		if (b >= c) return b;
		else return c;
	}
}

int solve(string a){
	int r = 0, g = 0, b = 0;
	for (char x: a){
		if (x == 'R'){
			r += 1;
		}else if(x == 'G'){
			g += 1;
		}else{
			b += 1;
		}
	}
	return a.length() - max(r, g, b);

}

int main(void){
	int t, n;
	char* ap;
	string a;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		ap = new char[n+1];
		scanf("%s",ap);
		a = ap;
		printf("%d\n",solve(a));
		free(ap);
	}
}