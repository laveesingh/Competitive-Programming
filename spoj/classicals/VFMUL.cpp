/*input
6
4 2
123 43
324 342
0 12
9999 12345
1 2343
*/

#include <bits/stdc++.h>
#include <complex>

using namespace std;

typedef complex<double> base;

void print(vector<int> a){
	for(int s: a){
		cout << s << " ";
	}
	cout << endl;
}

void fft(vector<base> &a, bool invert){
	int n = (int) a.size();
	if (n == 1) return;
	vector<base> a0(n/2), a1(n/2);
	for(int i = 0, j = 0; i < n; i += 2, j += 1){
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * M_PI/n * (invert ? -1 : 1);
	base w(1), wn(cos(ang), sin(ang));
	for(int i = 0; i < n/2; i += 1){
		a[i] = a0[i] + w*a1[i];
		a[i+n/2] = a0[i] - w*a1[i];
		if (invert)
			a[i] /= 2, a[i+n/2] /= 2;
		w *= wn;
	}
}

void poly_mult(const vector<int>& a, const vector<int>& b, vector<int>& c){
	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size())) n = n<<1;
	n = n<<1; // doubled the size actually.
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < n; i += 1){
		fa[i] *= fb[i];
	}
	fft(fa, true);
	c.resize(n);
	for(int i = 0; i < n; i += 1){
		c[i] = int(fa[i].real()+0.5);
	}
	int carry = 0;
	for (int i = n-1; i >= 0; i -= 1){
		c[i] += carry;
		carry = c[i]/10;
		c[i] %= 10;
	}
	if (carry > 0){
		cout << carry;
	}
	for(int i = 0; i < a.size()+b.size()-1; i += 1){
		cout << c[i];
	}
	cout << endl;
}

int main(void){
	ios::sync_with_stdio(false);
	string a, b;
	char temp[300001];
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--){
		scanf("%s", temp);
		// cin >> a;
		// cin >> b;
		a = temp;
		scanf("%s", temp);
		b = temp;
		if (a == "0" or b == "0"){
			cout << 0 << endl;
			continue;
		}
		vector<int> va, vb;
		for(char x: a){
			va.push_back(x-'0');
		}
		for (char x: b){
			vb.push_back(x-'0');
		}
		vector<int> vc;
		poly_mult(va, vb, vc);
	}
	// print(vc);

}