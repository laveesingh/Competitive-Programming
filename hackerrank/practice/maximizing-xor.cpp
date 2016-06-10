#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

struct node{
	struct node *children[2];
	bool isleaf;
}*root;

string binary(int a){
	stringstream ss;
	for (int i = 0; i < 16; i += 1){
		if (a%2){
			ss << 1;
		}else{
			ss << 0;
		}
		a /= 2;
	}
	string rev = ss.str();
	reverse(rev.begin(), rev.end());
	return rev;
}

char flip(char a){
	if (a == '1') return '0';
	return '1';
}

int integer(string a){
	int ans = 0;
	for (int i = 0; i < 16; i += 1){
		if(a[i] == '1'){
			ans += pow(2,16-i-1);
			// cout << "Increasing result with " << pow(2,16-i-1) << " i " << i << " 16-i-1 " << 16-i-1 << endl;
		}
	}
	return ans;
}

node *getnode(){
	node *pNode = (node *)malloc(sizeof(node));
	pNode->isleaf = false;
	pNode->children[0] = NULL;
	pNode->children[1] = NULL;
	return pNode;
}

void insert(string a){
	node *p = root;
	for (int i = 0; i < 16; i += 1){
		if(!p->children[a[i]-'0']){
			p->children[a[i]-'0'] = getnode();
		}
		p = p->children[a[i]-'0'];
	}
	p->isleaf = true;
}

int maxor(string a){
	node *p = root;
	string comp = "";
	for (int i = 0; i < 16; i += 1){
		int index = flip(a[i])-'0';
		// cout << "index: " << index << endl;
		if(!p->children[index]){
			// cout << "If i="<<i<<endl;
			if(i < 15) p = p->children[a[i]-'0'];
			comp.push_back(a[i]);
		}else{
			// cout << "Else i="<<i<<endl;
			if(i<15) p = p->children[index];
			comp.push_back(flip(a[i]));
		}
	}
	// cout << "Integers obtained are a : " << integer(a) << " comp: " << integer(comp) << endl;
	int ans = (integer(a)^integer(comp));
	// cout << "maximum xor : " << ans << endl;
	return ans;
}

int main(void){
	int l, r;
	cin >> l >> r;
	root = getnode();
	insert(binary(l));
	int maximum = 0;
	for (int i = l+1; i <= r; i += 1){
		// cout << "Checking for i = " << i << endl;
		maximum = max(maxor(binary(i)), maximum);
		insert(binary(i));
	}
	cout << maximum << endl;
}