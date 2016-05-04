#include <iostream>
#include <stack>


using namespace std;

bool isoperator(char x){
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') return true;
	return false;
}

void solve(string a){
	stack<int> st;
	char ans[a.length()+1];
	int ind = 0;
	for (int i = 0; i < a.length(); i += 1){
		if (isoperator(a[i])) st.push(a[i]);
		else if(a[i] == '('){
			// do nothing
		}else if(a[i] == ')'){
			ans[ind++] = st.top();
			st.pop();
		}else{
			ans[ind++] = a[i];
		}
	}
	ans[ind] = '\0';
	for (int i = 0; i < ind; i += 1){
		cout << ans[i];
	}
	cout <<endl;
}

int main(void){
	int t;
	cin >> t;
	while (t--){
		string a;
		cin >> a;
		solve(a);
	}
}