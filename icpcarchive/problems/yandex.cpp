#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class penguin{
public:
	char dir;
	int x;
	penguin(){}
	penguin(int a, char b){
		dir = b;
		x = a;
	}
	bool operator<(penguin other){
		if(x == other.x){
			return dir=='-';
		}
		return x < other.x;
	}

};

int main(void){
	int n;
	scanf("%d", &n);
	penguin a[n];
	char d;
	int xpos;
	for (int i = 0; i < n; i += 1){
		// cin >> xpos >> d;
		scanf("%d", &xpos);
		// fflush(stdin);
		scanf("%c", &d, 1);
		// fflush(stdin);
		a[i] = penguin(xpos, d);
	}
	sort(a, a+n);

	// for (int i = 0; i < n; i += 1){
	// 	cout << a[i].x << " " << a[i].dir << endl;
	// }
	int flag = 0;
	int ans = 1;
	for (int i = 0; i < n; i += 1){
		if(a[i].dir == '-'){
			flag =1;
		}
		if(flag == 1 && a[i].dir == '+'){
			ans = 2;
			break;
		}
	}
	// cout << ans << endl;
	printf("%d\n",ans);
}