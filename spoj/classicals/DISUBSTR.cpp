#include <iostream>
#include <algorithm>

using namespace std;

/*

* Let's construct suffix array for the first time with Time Complexity O(N(logN)^2))

*/

struct suffix{
	int index; // stores the origin index of the suffix in the string
	int rank[2]; // to store the rank and next rank
};

int comp(suffix a, suffix b){
	if(a.rank[0] == b.rank[0]){
		return a.rank[1] < b.rank[1];
	}else{
		return a.rank[0] < b.rank[0];
	}
}

int *suffixArr;
string str;

void buildSuffixArray(string txt, int n){
	suffix suffixes[n];
	for (int i = 0; i < n; i += 1){
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i]-'A';
		suffixes[i].rank[1] = ((i+1)<n ? txt[i+1]-'A' : -1);
	}
	sort(suffixes, suffixes+n, comp);
	int ind[n];
	for (int k = 4; k < 2*n; k *= 2){
		// cout << "Current suffix array is as follow:" << endl;
		// for (int i = 0; i < n; i += 1){
		// 	cout << suffixes[i].index << " " <<  txt.substr(suffixes[i].index, n-suffixes[i].index) << " " << suffixes[i].rank[0] << " " << suffixes[i].rank[1] << endl;
		// }
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;
		for(int i = 1; i < n; i += 1){
			if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}else{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}
		for (int i = 0; i < n; i += 1){
			int nextindex = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
		}
		sort(suffixes, suffixes+n, comp);
	}
	suffixArr = new int[n];
	for(int i = 0; i < n; i += 1){
		suffixArr[i] = suffixes[i].index;
	}
}

int lcp(int i, int j, int n){
	int length = 0;
	while(i < n && j < n){
		if(str[i++] == str[j++]){
			length++;
		}else{
			break;
		}
	}
	return length;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		cin >> str;
		int n = str.length();
		// cout << "Contructing suffix array for " << str << endl;
		buildSuffixArray(str, str.length());
		// cout << "Suffix array constructed" << endl;
		// for (int i = 0; i < n; i += 1){
		// 	cout << suffixArr[i] << " ";
		// }
		// cout <<endl;
		int ans = n - suffixArr[0];
		// cout << "Now calculating the final answer" << endl;
		for (int i = 1; i < n; i += 1){
			ans += ((n-suffixArr[i]) - lcp(suffixArr[i], suffixArr[i-1], n));
		}
		cout << ans << endl;
	}
}