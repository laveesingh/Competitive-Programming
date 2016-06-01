#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<int> prefix(string s){
	vector<int> p(s.length());
	p[0] = 0;
	for (int i = 1; i < s.length(); i += 1){
		int j = p[i-1];
		while (j > 0 && s[i] != s[j]){
			j = p[j-1];
		}
		if (s[i]==s[j]) p[i] = j+1;
		else p[i] = 0;
	}
	return p;
}

void solve(string s, string ans, string rev){
	vector<int> pre = prefix(s);
	int maxu = pre[pre.size()-1];
	for(int i = maxu; i < n; i += 1){
		ans.push_back(rev[i]);
	}
	cout << ans << endl;;
}

char temp[100001];

int main(void){
	while(scanf("%s",temp) == 1){
		string s = temp;
		string p = "";
		p += s;
		n = s.length();
		string tempo = "";
		reverse(p.begin(),p.end());
		tempo += p;
		p += "#";
		p += s;
		solve(p,s,p);
	}
}