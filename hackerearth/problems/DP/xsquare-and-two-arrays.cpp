#include <iostream>

using namespace std;

long long *ae, *ao, *be, *bo;


long long solve(long long nq, long long l, long long r){
	if (nq == 1){
		if (l == 0){
			return ae[r];
		}else if(l%2){
			return ao[r]-ao[l-1];
		}else{
			return ae[r]-ae[l-1];
		}
	}else{
		if (l == 0){
			return be[r];
		}else if(l%2){
			return bo[r]-bo[l-1];
		}else{
			return be[r]-be[l-1];
		}
	}
	return 0;
}

int main(void){
	long long n, q, ai, bi, nq;
	cin >> n >> q;
	long long a[n];
	long long b[n];
	ae = new long long[n];
	ao = new long long[n];
	be = new long long[n];
	bo = new long long[n];
	for (long long i = 0; i < n; i += 1){
		cin >> a[i];
	}
	for (long long i = 0; i < n; i += 1){
		cin >> b[i];
	}

	ae[0] = a[0];
	for (long long i = 1; i < n; i += 1){
		if (i%2){
			ae[i] = ae[i-1]+b[i];
		}else{
			ae[i] = ae[i-1]+a[i];
		}
	}
	ao[0] = 0;
	ao[1] = a[1];
	for (long long i = 2; i < n; i += 1){
		if (i%2){
			ao[i] = ao[i-1]+a[i];
		}else{
			ao[i] = ao[i-1]+b[i];
		}
	}

	be[0] = b[0];
	for (long long i = 1; i < n; i += 1){
		if (i%2){
			be[i] = be[i-1]+a[i];
		}else{
			be[i] = be[i-1]+b[i];
		}
	}

	bo[0] = 0;
	bo[1] = b[1];
	for (long long i = 2; i < n; i += 1){
		if (i%2){
			bo[i] = bo[i-1] + b[i];
		}else{
			bo[i] = bo[i-1] + a[i];
		}
	}


	for (long long query = 0; query < q; query += 1){
		cin >> nq >> ai >> bi;
		cout << solve(nq, ai-1, bi-1) << endl;
	}

}