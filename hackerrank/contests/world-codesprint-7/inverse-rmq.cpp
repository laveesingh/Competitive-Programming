#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

void print(vector<int> a){
	for(int s: a){
		cout << s << " ";
	}
	cout << endl;
}

bool good(const map<int, int>& freq, int n){
	// check if it's okay to convert back to the original array.
	// Frequencies of the elements should be as expected.
	return true;
}

void solve(int n, set<pair<int, int> > store, vector<int>& Original){
	set<pair<int, int> >::iterator it, it2;
	// take the parent out
	pii cur = *(store.rbegin());
	it = store.end();
	it2 = it;
	it2--;
	store.erase(it2, it);
	// use the parent and insert back the rest of freq's
	store.insert({cur.first-1, cur.second});
	Original.push_back(cur.second);
	// take the two children out, and partition the set into two different sets
	pii cur1 = *(store.rbegin());
	it = store.end();
	it2 = it;
	it2--;
	store.erase(it2, it);
	pii cur2 = *(store.rbegin());
	it = store.end();
	it2 = it;
	it2--;
	store.erase(it2, it);
	if(store.empty()){
		Original.push_back(min(cur1.second, cur2.second));
		Original.push_back(max(cur1.second, cur2.second));
	}else{
		pii left, right;
		set<pii> lset, rset;
		if (cur1.second > cur2.second){
			right = cur1;
			left = cur2;
		}else{
			left = cur1;
			right = cur2;
		}
		for(it = store.begin(); it != store.end(); it++){
			if (rset.size() == store.size()/2 or (*it).second < right.second){
				lset.insert(*it);
			}else{
				rset.insert(*it);
			}
		}
		lset.insert(left);
		rset.insert(right);
		solve(n, lset, Original);
		solve(n, rset, Original);
	}

}

int main(void){
	int n;
	cin >> n;
	int T[n];
	int m = 2*n-1;
	for(int i = 0; i < 2*n-1; i += 1){
		cin >> T[i];
	}
	map<int, int> ffreq, rfreq;
	for(int i = 0; i < m; i += 1){
		ffreq[T[i]] += 1;
	}
	if(not good(ffreq, n)){
		cout << "NO" << endl;
	}else{

		/*
			if the frequencies were okay as far as the terms are 
			concerned, but the order would ruin the entire segment tree,
			we'll check that later, once we've made the entire tree. So
			let's go ahead and build the entire segment tree using
			divide and conquer.
		*/
		set<pair<int, int> > store;
		for(map<int, int>::iterator it = ffreq.begin(); it != ffreq.end(); it++){
			store.insert({it->second, it->first});
		}
		for(set<pair<int, int> > :: iterator it = store.begin(); it != store.end(); it++){
			cout << (*it).first << " " << (*it).second << endl;
		}
		vector<int> Original;
		Original.reserve(m);
		solve(n, store, Original);
		// Now Original vector contains the original segment tree.
		// check if it's a correct segment tree, otherwise it can't be
		// reverted back
		cout << "YES" << endl; // Assuming the tree is good to go but this is not the case always
		print(Original);
	}
}