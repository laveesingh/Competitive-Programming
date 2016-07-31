#include <iostream>
#include <map>
#include <algorithm>


#define INF 1000000

using namespace std;

string a;
int k;

int func(int freq[], int minx, int k){
	int ans = 0;
	for(int i = 0; i < 26; i += 1){
		if (freq[i] != 0)
			ans += freq[i]-minx-k > 0 ? freq[i]-minx-k : 0;
	}
	return ans;
}

void Print(int a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int solve(string a, int k){
	int freq[26];
	fill_n(freq, 26, 0);
	// Print(freq, 26);
	for (char x: a){
		freq[x-'a'] += 1;
	}
	// Print(freq, 26);
	bool done = false;
	int no_of_elements_remaining = 26;
	for (int i = 0; i < 26; i += 1){
		if (freq[i] == 0){
			no_of_elements_remaining -= 1;
		}
	}
	if (no_of_elements_remaining == 1) done = true;
	int final = done == true ? 0 : INF;
	// Print(freq, 26);
	// cout << "Final init:" << final << endl;
	int characters_removed = 0;
	int flag = 0;
	while (!done){
		int minx = INF, mini;
		for (int i = 0; i < 26; i += 1){
			if (freq[i] != 0 && freq[i] < minx){
				minx = freq[i];
				mini = i;
			}
		}
		final = min(final, characters_removed+func(freq, minx, k));
		characters_removed += minx;
		freq[mini] = 0;
		no_of_elements_remaining -= 1;
		if (no_of_elements_remaining <= 1){
			final = min(final, characters_removed);
			done = true;
		} 
		// Print(freq, 26);
		// cout << "MINIMUM: " << final  << endl;
	}
	// Print(freq, 26);
	return final;

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