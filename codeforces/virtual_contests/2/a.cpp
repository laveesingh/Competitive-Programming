#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <set>

#define psi pair<string, int>
#define msi map<string, int>
#define mp make_pair
#define pb push_back

using namespace std;

int main(void){
	int n, score;
	cin >> n;
	msi points;
	string winner, name;
	int max_score = 0;
	vector<psi> input;
	while(n--){	
		cin >> name >> score;
		input.pb(mp(name, score));
		points[name] += score;
	}
	set<string> winners;
	for(msi::iterator it = points.begin(); it != points.end(); it++){
		max_score = max(max_score, it->second);
	}
	for(msi::iterator it = points.begin(); it != points.end(); it++){
		if(it->second == max_score){
			// cout << "pushing " << it->first << " into winners" << endl;
			winners.insert(it->first);
		}
	}
	// cout << "There are " << winners.size() << " elements  in winners " << endl;
	if(winners.size() == 1){
		// cout << "Only one winner" << endl;
		for(set<string>::iterator it = winners.begin(); it != winners.end(); it++){
			cout << *it << endl;
		}
	}else{
		points.clear();
		for (int i = 0; i < input.size(); i +=1){
			if(winners.find(input[i].first) != winners.end()){
				points[input[i].first] += input[i].second;
				if (points[input[i].first] >= max_score){
					cout << input[i].first << endl;
					break;
				}
			}
		}
	}
}