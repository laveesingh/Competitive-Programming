#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

string Copy(string a){
	return a;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string vil;
		cin >> vil;
		string vil1 = Copy(vil);
		string vil2 = Copy(vil);

		int dist[n];
		for (int i = 0; i < n; i += 1){
			cin >> dist[i];
		}
		int rwire[n];
		fill_n(rwire, n, INF);
		for(int i = 1; i < n; i += 1){
			if(vil1[i] == '1'){
				rwire[i] = 0;
			}else{
				if(vil1[i-1] == '1'){
					rwire[i] = min(rwire[i], dist[i]-dist[i-1]);
					vil1[i] = '1';
				}
			}
		}
		for (int i = n-2; i >= 0; i -= 1){
			if(vil2[i] == '1'){
				rwire[i] = 0;
			} else {
				if(vil2[i+1] == '1'){
					rwire[i] = min(rwire[i], dist[i+1]-dist[i]);
					vil2[i] = '1';
				}
			}
		}
		// cout << endl << endl;
		// for (int i = 0; i < n; i +=1){
		// 	cout << rwire[i] << " ";
		// }
		// cout << endl << endl << endl;
		cout << accumulate(rwire, rwire+n, 0) << endl;
	}
}