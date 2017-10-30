#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void){

	long long m, n, a, answer;
	cin >> n >> m >> a;
	answer = (long long)(ceil((double)m/a)*ceil((double)n/a));
	//cout << ans << endl;
	//printf("%lld\n", answer);
	cout << answer << endl;
}