#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a, b;
	char x;
	cin >> a >> x >> b;
	if(n == 12){
		if(a > 12 or a < 1){
			int rem = a%10;
			if(rem == 0){
				a = 10;
			}else{
				a = rem;
			}
		}
		if (b > 59){
			int rem = b%10;
			b = 30 + rem;
		}
	}else{
		if(a > 23){
			int rem = a%10;
			a = 10+rem;
		}
		if(b > 59){
			int rem = b%10;
			b = 30 + rem;
		}
	}
	printf("%02d:%02d\n", a, b);
}