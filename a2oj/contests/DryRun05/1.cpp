#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define INF 1000000

int main(void){
	int n;
	scanf("%d", &n);
	int a[n];
	map<int, int> freq;
	map<int, int> findex, lindex;
	int maxfreq = 0;
	
	for (int i = 0; i<n; i += 1){
		scanf("%d",&a[i]);
		freq[a[i]] += 1;
		maxfreq = max(maxfreq, freq[a[i]]);
		
	}
	for (int i = 0; i < n; i += 1){
		findex[a[i]] = INF;
	}

	for (int i = 0; i < n; i += 1){
		findex[a[i]] = min(findex[a[i]], i);
		lindex[a[i]] = max(lindex[a[i]], i);
	}
	int ffindex=0, flindex=n-1;
	// for (map<int, int>::iterator it = findex.begin(); it != findex.end(); it++){
	// 	cout << "First index of " << it->first << " is " << it->second << endl;
	// }
	// for (map<int, int>::iterator it = lindex.begin(); it != lindex.end(); it++){
	// 	cout << "Last index of " << it->first << " is " << it->second << endl;
	// }
	for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == maxfreq){
			int tfindex = findex[it->first];
			int tlindex = lindex[it->first];
			if(tlindex-tfindex < (flindex-ffindex)){
				ffindex = tfindex;
				flindex = tlindex;
			}
		}
	}
	printf("%d %d\n", ffindex+1, flindex+1);

}