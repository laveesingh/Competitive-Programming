#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int a[n1], b[n2], c[n3];
	for (int i = 0; i<n1; i += 1){
		cin >> a[i];
	}
	for (int i = 0; i<n2; i += 1){
		cin >> b[i];
	}
	for (int i = 0; i<n3; i += 1){
		cin >> c[i];
	}
	int s1, s2, s3;
	reverse(a, a+n1);
	reverse(b,b+n2);
	reverse(c,c+n3);
	s1 = accumulate(a, a+n1, 0);
	s2 = accumulate(b, b+n2, 0);
	s3 = accumulate(c, c+n3, 0);
	int i = n1-1, j = n2-1, k = n3-1;
	while (s1 != s2 || s2 != s3){
		if(s1 > s2 || s1 > s3){
			s1 -= a[i--];
		}
		if(s2 > s3 || s2 > s1){
			s2 -= b[j--];
		}
		if (s3 > s2 || s3 > s1){
			s3 -= c[k--];
		}
	}
	cout << s1 << endl;
}