#include <iostream>
#include <map>


using namespace std;

int main(void){
	int n;
	cin >> n;
	map<string, int> store;
	string winner,name ;
	int maxscore = 0;
	for (int i = 0; i < n; i += 1){
		cin >> name;
		store[name] += 1;
		if(store[name] > maxscore){
			winner = name;
			maxscore = store[name];
		}
	}
	cout << winner << endl;
}