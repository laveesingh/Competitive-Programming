#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

void print(set<pii> a){
	set<pii>::iterator it;
	for(it = a.begin(); it != a.end(); it++){
		cout << (*it).first << " " << (*it).second << ",  ";
	}
	cout << endl;
}

int main(void){
	set<pii> a;
	a.insert({1,2});
	a.insert({2,3});
	a.insert({2,1});
	a.insert({2,9});
	a.insert({2,4});
	a.insert({2,2});
	a.insert({2,5});

	print(a);

}