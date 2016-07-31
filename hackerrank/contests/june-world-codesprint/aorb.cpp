#include <iostream>
#include <deque>
#include <map>
#include <sstream>

using namespace std;

const string letters = "0123456789ABCDEF";

string bins[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

map<char, string> hex2bin;
map<string, char> bin2hex;

void sethexbin(){
	for (int i = 0; i < 16; i += 1){
		hex2bin[letters[i]] = bins[i];
		bin2hex[bins[i]] = letters[i];
	}
}


string hextobin(string a){
	string ans = "";
	// cout << "Working in hextobin. Current answer is " << ans << endl;
	for (int i = 0; i < a.length(); i += 1){
		// cout << "Appending " << hex2bin[a[i]] << endl;
		ans.append(hex2bin[a[i]]);
		// cout << "Current answer is " << ans << endl;
	}
	return ans;
}

string bintohex(string a){
	// cout << "Doing bintohex for " << a << endl;
	string ans = "";
	for (int i = 0; i < a.length(); i += 4){
		ans.push_back(bin2hex[a.substr(i,4)]);
	}
	return ans;
}

void equalize(string& a, string& b){
	int n = a.length();
	int m = b.length();
	if (n > m){
		int l = n-m;
		stringstream ss;
		for (int i = 0; i < l; i += 1){
			ss << 0;
		}
		ss << b;
		b = ss.str();
	}else if (n < m){
		int l = m-n;
		stringstream ss;
		for (int i = 0; i< l; i += 1){
			ss << 0;
		}
		ss << a;
		a = ss.str();
	}
}

void ltrim_zeroes(string& a){
	int i = 0;
	int n = a.length();
	while(i < n-1 && a[i] == '0'){
		i += 1;
	}
	a = a.substr(i, n-i);
}

void solve(string ahex, string bhex, string chex, int k){
	// cout << "ahex is " << ahex << endl;
	// cout << "bhex is " << bhex << endl;
	// cout << "chex is " << chex << endl;
	string abin = hextobin(ahex);
	string bbin = hextobin(bhex);
	string cbin = hextobin(chex);
	// cout << "abin is " << abin << endl;
	// cout << "bbin is " << bbin << endl;
	// cout << "cbin is " << cbin << endl;
	equalize(abin, bbin);
	equalize(bbin, cbin);
	// cout << "abin is " << abin << endl;
	// cout << "bbin is " << bbin << endl;
	// cout << "cbin is " << cbin << endl;
	for (int i = 0; i < abin.length(); i += 1){
		if (k <= 0) break;
		if(cbin[i] == '1'){
			if(abin[i] == '1' || bbin[i] == '1'){
				// do nothing
			} else {
				bbin[i] = '1';
				k -= 1;
			}
		} else {
			if (abin[i] == '0' && bbin[i] == '0'){
				// do nothing
			} else {
				if (abin[i] == '1'){
					abin[i] = '0';
					k -= 1;
					if (k <= 0) break;
				}
				if(bbin[i]  == '1'){
					bbin[i] = '0';
					k -= 1;
				}
			}
		}
	}


	// check whether we're succcessful in establishing a|b=c
	for (int i = 0; i < cbin.length(); i += 1){
		if(cbin[i] == '1'){
			if(abin[i] == '1' || bbin[i] == '1'){
				// do nothing
			} else {
				cout << -1 << endl;
				return;
			}
		} else {
			if(abin[i] == '1' || bbin[i] == '1'){
				cout << -1 << endl;
				return;
			}
		}
	}
	// cout << "abin is " << abin << endl;
	// cout << "bbin is " << bbin << endl;
	// cout << "k is " << k << endl;
	int i = 0;
	while (k > 0 && i < cbin.length()){
		// cout << "k " << k << " i " << i << endl;
		if(cbin[i] == '1'){
			if(abin[i] == '1' && bbin[i] == '1'){
				abin[i] = '0';
				k -= 1;
			}else if(abin[i] == '1' && bbin[i] == '0' && k >= 2){
				abin[i] = '0';
				bbin[i] = '1';
				k -= 2;
			}
		}
		i += 1;
	}
	ahex =  bintohex(abin);
	bhex =  bintohex(bbin);
	ltrim_zeroes(ahex);
	ltrim_zeroes(bhex);
	cout << ahex << endl << bhex << endl;
	return;
}

int main(){
	sethexbin();
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		string ahex, bhex, chex;
		cin >> ahex >> bhex >> chex;
		solve(ahex, bhex, chex, k);
	}
}