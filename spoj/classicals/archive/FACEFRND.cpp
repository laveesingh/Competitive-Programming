#include <iostream>
#include <map>
#include <set>

using namespace std;

#define present(cont, elem) (cont.find(elem) != cont.end())

int main(void){
	int n;
	cin >> n;
	map<int, set<int> > fb;
	set<int> visited;
	set<int> friends;
	int count = 0;
	while(n--){
		int ffnd, fnd;
		cin >> fnd;
		int no;
		cin >> no;
		friends.insert(fnd);
		for (int i =0; i < no; i += 1){
			cin >> ffnd;
			fb[fnd].insert(ffnd);
		}
	}
	for(map<int, set<int> >::iterator it = fb.begin(); it != fb.end(); ++it){
		set<int> fof = it->second;
		int frnd = it->first;
		for(set<int>::iterator it2 = fof.begin(); it2 != fof.end(); ++it2){
			if (present(visited, *it2) || present(friends, *it2)){
				// do nothing
			}else{
				visited.insert(*it2);
				count += 1;
			}
		}
	}
	cout << count << endl;
}