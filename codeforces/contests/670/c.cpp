#include <iostream>
#include <map>

using namespace std;

class movie{
public:
	int aud, subt, vp, ap;
	movie(){
		aud = 0;
		subt =0;
		vp = 0;
		ap = 0;
	}
	movie(int a, int s){
		aud = a;
		subt = s;
	}
};

int main(void){
	int n, m;
	cin >> n;
	int sc[n];
	for (int i = 0; i < n ;i += 1 ) cin >> sc[i];
	cin >> m;
	movie movies[m];
	int audios[m];
	int subs[m];
	for (int i = 0; i < m; i += 1){
		cin >> audios[i];
	}
	for (int i = 0; i < m; i += 1){
		cin >> subs[i];
	}
	for (int i = 0; i < m ; i += 1){
		movies[i] = movie(audios[i], subs[i]);
	}
	map<int, int> freq;
	for (int i = 0; i < n; i += 1){
		freq[sc[i]] += 1;
	}
	int maxa = 0;
	int maxb = 0;
	int final = 0;
	for (int i = 0; i < m; i += 1){
		movies[i].vp = freq[movies[i].aud];
		movies[i].ap = freq[movies[i].subt];
		if (movies[i].vp > maxa){
			maxa = movies[i].vp;
			maxb = movies[i].ap;
			final = i;
		}else if(movies[i].vp == maxa && movies[i].ap > maxb){
			maxb = movies[i].ap;
			final = i;
		}
	}
	cout << final+1 << endl;


}