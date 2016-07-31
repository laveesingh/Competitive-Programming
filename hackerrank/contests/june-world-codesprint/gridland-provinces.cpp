#include <cstdio>
#include <iostream>
#include <utility>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define pii pair<int, int>
#define piis pair<pair<int, int>, string>
#define mp make_pair
#define pb push_back
#define pf pop_front

// int **visited, n;
int n;
map<pii, int> visited;
int Xcord[] = {1, 0, -1, 0};
int Ycord[] = {0, 1, 0, -1};

bool isvalid(int i, int j){
	if(i < 0 || i > 1){
		return false;
	} else if(j < 0 || j > n-1){
		return false;
	} else if(visited[mp(i,j)]){
		return false;
	}
	return true;
}

int main(void){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		string a[2];
		cin >> a[0];
		cin >> a[1];
		set<string> dstrings;// distinct strings
		for (int j = 0; j < n; j += 1){
			for (int i = 0; i < 2; i += 1){
				cout << "Initiating : " << i << "  " << j << endl;
				string temps = "";
				temps.pb(a[i][j]);
				piis cur = mp(mp(i, j), temps);
				deque<piis> stack;
				stack.pb(cur);
				visited.clear();
				visited[mp(i,j)] = 1;
				while(!stack.empty()){
					cur = stack.front();
					stack.pf();
					int I = cur.first.first;
					int J = cur.first.second;
					temps = cur.second;
					cout << "Current status is : " << I << " " << J << " " << temps << endl;
					if(temps.length() == 2*n){
						dstrings.insert(temps);
					}
					for (int k = 0; k < 4; k += 1){
						int tempI = I+Xcord[k];
						int tempJ = J+Ycord[k];
						if(isvalid(tempI, tempJ)){
							visited[mp(tempI,tempJ)] = 1;
							temps.pb(a[tempI][tempJ]);
							cur = mp(mp(tempI, tempJ), temps);
							stack.pb(cur);
						}else{
						}
					}
				}
			}
		}
		cout << dstrings.size() << endl;
		for (set<string>::iterator it = dstrings.begin(); it != dstrings.end(); it++){
			cout << *it << endl;
		}
	}
}

