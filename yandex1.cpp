#include <iostream>
#include <algorithm>

using namespace std;

class actor{
public:
	int salary, coolness;
	string phrase;
	actor(){}
	actor(int sal, int cool, string ph){
		salary = sal;
		coolness = cool;
		phrase = ph;
	}
	bool operator<(actor other){
		return coolness < other.coolness;
	}
};

int main(void){
	int n,  m, ci, li;
	cin >> n >> m;
	string plot, tphrase;
	cin >> plot;
	int freq[26];
	fill_n(freq, 26, 0);
	for (char x: plot){
		freq[x-'0'] += 1;
	}
	actor actors[m];
	for (int i = 0; i < m; i += 1){
		cin >> li >> ci >> tphrase;
		actors[i] = actor(0, ci, tphrase);
	}
	sort(actors, actors+m);
	for (int i = 0; i < m; i += 1){
		tphrase = actors[i].phrase;
		cout << "Current phrase : " << tphrase << endl;
		for (char x: tphrase){
			if(freq[x-'0'] > 0){
				cout << x << " found in " << i+1 << " actor " << endl;
				freq[x-'0'] -= 1;
				actors[i].salary += 1;
			}
		} 
	}
	int cost = 0;
	for (int i = 0; i < m; i += 1){
		cost += actors[i].coolness * actors[i].salary;
	}
	cout << cost << endl;
}