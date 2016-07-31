#include <iostream>

using namespace std;


int main(void){
	int t;
	cin >> t;
	int n, bugs, rank;
	string temp, origin;

	while (t--){
		cin >> n >> origin;
		int laddus = 0;
		for (int i = 0; i < n; i += 1){
			cin >> temp;
			if (temp == "TOP_CONTRIBUTOR") laddus += 300;
			else if(temp == "CONTEST_HOSTED"){
				laddus += 50;
			}else if(temp == "CONTEST_WON"){
				cin >> rank;
				laddus += 300;
				if (rank < 20) laddus += 20-rank;
			}else{
				cin >> bugs;
				laddus += bugs;
			}
		}
		if (origin == "INDIAN") cout << laddus/200 << endl;
		else cout << laddus/400 << endl;;
	}
}