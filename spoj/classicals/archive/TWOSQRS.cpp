#include <cstdio>
#include <cmath>

using namespace std;

bool isSqrt(long long n){
	return sqrt(n) == (long long)sqrt(n);
}

bool isHptns(long long n){
	for (long long i = 0; i <= (long long)sqrt(n)+1; i += 1){
		if (isSqrt(n-i*i)){
			return true;
		}
	}
	return false;
}

int main(void){
	long long t, n;
	// cin >> t;
	scanf("%lld", &t);
	while (t--){
		// cin >> n;
		scanf("%lld", &n);
		// cout << (isHptns(n) ? "Yes" : "No" )<< endl;;
		printf("%s\n", (isHptns(n)?"Yes":"No"));
	}
}