#include <iostream>
#include <map>


#define INF 1000000

using namespace std;

int solve(string a, int k){
	int minfreq = INF;
	map<char, int> freq;
	int ans = 0,y;
	for (int i = 0; i < a.length(); i += 1){
		freq[a[i]] += 1;
		
	}
	for (map<char, int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second < minfreq)minfreq=it->second;
	}

	// cout << "Minimum frequency: " << minfreq << endl;
	for (map<char, int>::iterator it = freq.begin(); it != freq.end(); it++){
		// cout << it -> first << "==>" << it->second << endl;
		y = it->second;
		if (y-minfreq > k){
			ans += y-minfreq-k;
		}
	}
	return ans;

}

int main(void){
	int t, k;
	cin >> t;
	string a;
	while(t--){
		cin >> a >> k;
		cout << solve(a, k) << endl;
	}
}