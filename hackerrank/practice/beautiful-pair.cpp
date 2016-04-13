#include <set>
#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	multiset<int> ms;
	for (int i = 0; i < n; i += 1){
		int temp;
		cin >> temp;
		ms.insert(temp);
	}
	multiset<int> :: iterator it;
	int ans = 0;
	for (int i = 0; i < n; i += 1){
		it = ms.find(a[i]);
		if (it == ms.end()) continue;
		ans += 1;
		ms.erase(it);
	}
	if ((int)ms.size() == 0){
		ans-= 1;
	}else{
		ans += 1;
	}
	cout << ans << endl;
}