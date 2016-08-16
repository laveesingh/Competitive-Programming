/*input
1
4
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	if (n == 1){
		cout << 2 << endl;
	}else if(n== 2){
		if (a[0] == a[1]){
			cout << 2 << endl;
		}else{
			cout << 1 << endl;
		}
	}else{
		multiset<double> st(a, a+n);
		double sum = accumulate(a, a+n, (double)0);
		// cout << "n is " << n  << " and initial sum " << sum << endl;
		int cuts = 0;
		double boss = *(st.rbegin());
		sum -= boss;
		while (sum <= boss){
			// cout << "sum " << sum << " boss " << boss << endl;
			cuts += 1;
			st.erase(boss);
			sum += boss;
			double heir = boss/2;
			st.insert(heir);
			st.insert(heir);
			boss = *(st.rbegin());
			sum -= boss;
		}
		// cout << "Out of the loop" << endl;
		// cout << sum << " " << boss << endl;
		cout << cuts << endl;
	}

}