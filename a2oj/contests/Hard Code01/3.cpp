#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin >>n;
	int a;
	int count1=0, count0=0, count0max=-1;
	for(int i = 0; i < n; i += 1){
		cin >> a;
		if(a==1){
			count1++;
			if(count0 > 0){
				count0--;
			}
		}else{
			count0++;
			count0max = max(count0,count0max);
		}
	}
	cout << (count1+count0max) << endl;
}