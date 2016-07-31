#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, temp;
		cin >> n;
		int freq[1001];
		fill_n(freq,1001,0);
		for (int i = 0; i < n; i += 1){
			cin >> temp;
			freq[temp] += 1;
		}
		vector<int> twins;
		for (int i = 1; i < 1001; i += 1){
			if (freq[i] >= 4){
				twins.push_back(i);
				twins.push_back(i);
			}else if(freq[i] >= 2){
				twins.push_back(i);
			}
		}
		if (twins.size() < 2){
			cout << -1 << endl;
		} else {
			sort(twins.begin(), twins.end());
			int area = 1;
			area *= twins.back();
			twins.pop_back();
			area*=twins.back();
			cout << area << endl;
		}
	}
}