#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

char* add(string a, string b){
	int i = 0, j = 0, carry = 0, sum, ind=0;
	int n = a.length(), m   = b.length();
	// string ans="";
	char* ans = new char[max(n,m)];
	while (i < n || j < m){
		if (i < n && j < m){
			sum = carry+(a[i]-'0')+(b[j]-'0');
			i += 1;
			j += 1;
			
		}else if(i < n){
			sum = carry+(a[i]-'0');
			i += 1;

		}else{
			sum = carry + (b[j]-'0');
			j += 1;
		}
		if (ind==0 && sum%10==0){
			//do nothing
		}else{

			// ans.append(to_string(sum % 10));
			
			ans[ind] = sum%10 + 48;
			ind += 1;
		}
		carry = sum/10;
	}
	if (carry != 0){
		// ans.append(to_string(carry));
		ans[ind] = carry + 48;
	}
	return ans;
}

int main(void){
	int t;

	string a, b;
	// cin >> t;
	scanf("%d", &t);
	while (t--){
		// cin >> a >> b;
		char temp[11];
		scanf("%s", temp);
		a = temp;
		scanf("%s", temp);
		b = temp;
		// cout << add(a, b) << endl;
		printf("%s\n", add(a, b));
		
	}
	// int x = 9;
	// char y = x + 48;
	// cout << y << endl;
}