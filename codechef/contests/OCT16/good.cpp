#include <bits/stdc++.h>

using namespace std;

bool visited[20];

bool is_good(string s,int n){
	fill_n(visited,n+1,false);
	int c=0,i=0;
	bool ans=true;
	while(true){
		visited[i]=true;
		c++;
		if(i==(n-1)){
			break;
		}
		if(s[i]=='1'){
			if((i-1)>=0 and !visited[i-1]){
				i=i-1;
			}
			else if((i+1)<n and !visited[i+1]){
				i=i+1;
			}
			else{
				ans=false;
				break;
			}
		}
		else if(s[i]=='2'){
			if((i-2)>=0 and !visited[i-2]){
				i=i-2;
			}
			else if((i+2)<n and !visited[i+2]){
				i=i+2;
			}
			else{
				ans=false;
				break;
			}
		}
	}
	if(c!=n){
		ans=false;
	}
	return ans;
}

int main(void){
	string a;
	int n;
	cin >> n;
	for(int i = 0; i < n; i+=1){
		cin >> a;
		cout << (is_good(a, a.length()) ? "YES" : "NO") << endl;
	}
}
