#include <iostream>
#include <cmath>

using namespace std;

void solve(int l1, int w1, int l2, int w2){
	int min_area, max_area;
	if ((l2 <= l1 && w2 <= w1) || (l1 <= l2 && w1 <= w2)){
		min_area = max(l1, l2)*max(w2,w1);
	}else{
		min_area = abs(l1-l2)*min(w1,w2) +
					abs(w1-w2)*min(l1, l2) + 
					min(l1, l2)*min(w1, w2);
	}
	max_area = l1*w1 + l2*w2;
	cout << min_area << " " << max_area << endl;
}

int main(void){
	int t ;
	cin >> t;
	int l1, w1, l2, w2;
	while (t--){
		cin >> l1 >> w1 >> l2 >> w2;
		solve(l1, w1, l2, w2);
	}
}