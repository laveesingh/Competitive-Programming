#include <iostream>
#include <deque>
#include <utility>
#include <map>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int N, M, s;
int *A;
deque<pii> q;
map<int, int> f;

// void solve(int N, int M, int s, int A[]){
void solve(){
	pii cur;
	int dog, m;

	q.push_back(mp(s,0));
	while(!q.empty()){
		cur = q.front();
		q.pop_front();
		dog = cur.first;
		m = cur.second;
		// cout << "DOG: " << dog << " turn: " << m;
		if (m == M){
			f[dog] += 1;
		}else if(m < M){
			if (dog+A[m] <= N){

				q.push_back(mp(dog+A[m], m+1));
				// cout << "Appending dog: " << dog+A[m] << " ";
			}
			if (dog-A[m] > 0){
				q.push_back(mp(dog-A[m], m+1));
				// cout << "Appending dog : " << dog-A[m] << " ";
			}
		}
		// cout << endl;
	}
	for (int i = 1; i <= N; i += 1){
		cout << f[i] << " ";
	}
	cout << endl;
}

int main(void){
	// int t, N, M, s;
	int t;
	cin >> t;
	while (t--){
		q.clear();
		f.clear();
		cin >> N >> M >> s;
		// int A[M];
		A = new int[M];
		for (int i = 0; i < M; i += 1){
			cin >> A[i];
		}
		// solve(N, M, s, A);
		solve();
		delete[] A;

	}
}