#include <iostream>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int count = 0;
	while (n > 0 and m > 0 and n+m > 2){
		if(n > m){
			n -= 2;
			m -= 1;
			count++;
		}else{
			m -= 2;
			n -= 1;
			count++;
		}
	}
	cout << count << endl;
}