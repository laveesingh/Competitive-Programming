#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

int main(void){
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	vector<string> moves;
	while(s != t){
		if(s[0] < t[0] && s[1] > t[1]){
			s[0] += 1;
			s[1] -= 1;
			moves.pb("RD");
		}else if(s[0] < t[0] && s[1] < t[1]){
			s[0] += 1;
			s[1] += 1;
			moves.pb("RU");
		}else if(s[0] > t[0] && s[1] > t[1]){
			s[0] -= 1;
			s[1] -= 1;
			moves.pb("LD");
		}else if(s[0] > t[0] and s[1] < t[1]){
			s[0] -= 1;
			s[1] += 1;
			moves.pb("LU");
		}else if(s[0] < t[0]){
			s[0] +=1;
			moves.pb("R");
		}else if(s[0] > t[0]){
			s[0] -= 1;
			moves.pb("L");
		}else if(s[1] > t[1]){
			s[1] -= 1;
			moves.pb("D");
		}else{
			s[1] += 1;
			moves.pb("U");
		}
	}
	cout << moves.size() << endl;
	for(int i = 0; i < moves.size(); i += 1){
		cout << moves[i] << endl;
	}
}