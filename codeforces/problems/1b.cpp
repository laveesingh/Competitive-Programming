#include <iostream>
#include <string>

using namespace std;

string letters = "ZABCDEFGHIJKLMNOPQRSTUVWXY";

int pow(int a, int b){
	int res = 1;
	while(b--){
		res *= a;
	}
	return res;
}

int main(void){
	int n;
	cin >> n;
	string a;
	int row, col;
	string rows, cols;
	while(n--){
		cin >> a;
		rows = "";
		cols = "";
		bool flag1 = false, flag2 = false;
		string temprow="", tempcol="";
		// cout << "Input taken" << endl;
		for (int i = 0; i < a.length(); i += 1){
			if(flag1 == false && flag2 == false && isalpha(a[i])){
				rows += a[i];
			}else if(flag2 == true && isalpha(a[i])){
				cols += a[i];
				flag1 = true;
			}else if(flag1 == false  && isdigit(a[i])){
				temprow += a[i];
				flag2 = true;
			}else if(flag1 == true && flag2 == true && isdigit(a[i])){
				tempcol += a[i];
			}
		}
		// cout << "Out of first for loop" << endl;
		if(tempcol != ""){
			int col = stoi(tempcol);
			string newcol = "";
			while(col > 26){
				// newcol.push_back(letters[col%26]);
				newcol = letters[col%26]+newcol;
				if(col%26 == 0 && col/26 < 26){
					col--;
				}
				col /= 26;
			}
			newcol = letters[col%26] + newcol;
			cout << newcol << temprow << endl;
		}else{
			int newcol = 0;
			// cout << "rows="<<rows << endl;
			for(int i = 0; i < rows.length(); i += 1){
				int mult = pow(26,rows.length()-i-1);
				// cout << "Multiplier is " << mult << endl;
				newcol += (mult)*(rows[i]-'A'+1);
				// cout << newcol << endl;
			}
			cout << "R"<<temprow<<"C"<<newcol << endl;
		}
	}
}