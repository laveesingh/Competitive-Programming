#include <iostream>

using namespace std;

#define F(i,n) for (int i = 0; i < n; i += 1)

bool isval(int i, int j){
	if (i >= 0 && j >= 0 && i < 3 && j < 3) return true;
	return false;
}

int main(void){
	int a[3][3];
	int b[3][3];
	F(i,3){
		F(j,3){
			cin >> b[i][j];
		}
	}
	F(i,3){
		F(j,3){
			a[i][j]  = 0;
		}
	}
	// F(i,3){
	// 	F(j,3){
	// 		cout << a[i][j]<<" " ;
	// 	}
	// 	cout<<endl;
	// }
	F(i,3){
		F(j,3){
			if (b[i][j] != 0){

				if(isval(i+1,j)){
					a[i+1][j] += b[i][j];
				}
				if (isval(i-1,j)){
					a[i-1][j] += b[i][j];
				}
				if (isval(i,j+1)){
					a[i][j+1] += b[i][j];
				}
				if(isval(i,j-1)){
					a[i][j-1] += b[i][j];
				}
				a[i][j] += b[i][j];
			}

		}
	}
	// F(i,3){
	// 	F(j,3){
	// 		cout << a[i][j]<<" " ;
	// 	}
	// 	cout<<endl;
	// }
	F(i,3){
		F(j,3){
			if(a[i][j]%2){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
		cout<<endl;
	}

}