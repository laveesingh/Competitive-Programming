#include <iostream>
#include <algorithm>

using namespace std;

class person{
public:
	int d,m,y;
	string name;
	bool operator<(person a){
		if(y < a.y) return true;
		if(y > a.y) return false;
		if(m < a.m) return true;
		if(m > a.m) return false;
		return d < a.d;
	}
};

int main(void){
	int n;
	cin >> n;
	string name;
	int day, month, year;
	person a[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i].name >> a[i].d >> a[i].m >> a[i].y;
	}
	sort(a, a+n);
	cout << a[n-1].name << endl << a[0].name << endl;
}