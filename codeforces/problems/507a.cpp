#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int sum(int a[], int n){
	int temp= 0;
	for (int i = 0; i < n; i += 1){
		temp += a[i];
	}
	return temp;
}

void solve(int n, int k, int a[]){
	map<int, vector<int>> ind;
	for (int i = 0; i < n; i += 1){
		ind[a[i]].push_back(i);
	}
	vector<int> temp;
	int total = 0;
	for (map<int, vector<int>>::const_iterator it = ind.begin(); it != ind.end(); it++){
		vector<int> tempv;
		tempv = it->second;
		int val = it-> first;
		for (int i = 0; i < tempv.size(); i += 1){
			total += val;
			if (total <= k){
				temp.push_back(tempv[i]+1);
			}else{
				break;
			}
		}
		
	}
	cout << temp.size() << endl;
	for (int i = 0; i < temp.size(); i += 1){
		cout << temp[i] << " " ;
	}
	cout << endl;


 }

 void print(vector<int> a){
 	for (int i = 0; i < a.size(); i += 1){
 		cout << a[i] << " ";
 	}
 }

int main(void){
	int n, k;
	cin >> n >> k;
	int a[n];
	for( int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	solve(n, k , a);
	
}