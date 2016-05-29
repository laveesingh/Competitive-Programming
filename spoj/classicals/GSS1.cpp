#include <iostream>
#include <map>
#include <vector>
#include <utility>

#define mp make_pair
#define pii pair<int, int>

using namespace std;

class node{
public:
	int L, R, Total, Left, Right, Mid, Max;
	// node(){}
	node(int Li=0, int Ri=0, int Totali=0, int Lefti=0, int Righti=0, int Midi=0, int Maxi=0){
		L = Li;
		R = Ri;
		Total = Totali;
		Left = Lefti;
		Right= Righti;
		Mid = Midi;
		Max = Maxi;

	}
};

int add(int x, int y){
	if (x >= 0 && y >= 0) return x+y;
	if (x > y) return x;
	return y;
}

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int max(int a, int b, int c, int d, int e, int f){
	return max(max(max(a,b),max(c,d)), max(e,f));
}

int main(void){
	int n, m, qx, qy;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i += 1){
		cin >> arr[i];
	}
	map<pii, int> tree;
	vector<node> t1, t2, t3;
	node temp, tempa, tempb;
	for (int i = 0; i < n; i += 1){
		temp = node(i, i, arr[i], arr[i], arr[i], arr[i], arr[i]);
		t1.push_back(temp);
		tree[mp(i,i)] = arr[i];
	}
	bool done = false;
	while(!done){
		if (!t1.empty()){
			for (int i = 0; i < t1.size(); i += 2){
				tempa = t1[i];
				tempb = t1[i+1];
				temp = node();
				temp.L = tempa.L;
				temp.R = tempb.R;
				temp.Left = max(tempa.Left, tempa.Total+tempb.Left);
				temp.Right = max(tempb.Right, tempb.Total+tempa.Right);
				temp.Mid = tempa.Right + tempb.Left;
				temp.Total = tempa.Total + tempb.Total;
				temp.Max = max(tempa.Max, tempb.Max, temp.L, temp.R, temp.Mid, temp.Total);
				t2.push_back(temp);
				tree[mp(temp.L, temp.R)] = temp.Max;
				if (i == t1.size()-3){
					t2.push_back(t1[i+2]);
					break;
				}

			}
			t1.clear();
			if (t2.size() == 1) done  = true;
		}else{
			for (int i = 0; i < t2.size(); i += 2){
				tempa = t2[i];
				tempb = t2[i+1];
				temp.L = tempa.L;
				temp.R = tempb.R;
				temp.Left = max(tempa.Left, tempa.Total+tempb.Left);
				temp.Right = max(tempb.Right, tempb.Total+tempa.Right);
				temp.Mid = tempa.Right + tempb.Left;
				temp.Total = tempa.Total + tempb.Total;
				temp.Max = max(tempa.Max, tempb.Max, temp.L, temp.R, temp.Mid, temp.Total);
				t1.push_back(temp);
				tree[mp(temp.L, temp.R)] = temp.Max;
				if (i == t2.size()-3){
					t1.push_back(t1[i+2]);
					break;
				}
			}
			t2.clear();
			if(t1.size() == 1) done = true;
		}

	}
	for (map<pii, int>::iterator it = tree.begin(); it != tree.end(); it++){
		cout << it->first.first << ", " << it->first.second << " => " << it->second << endl;
	}
	cin >> m;
	while (m--){
		cin >> qx >> qy;
		cout << tree[mp(qx, qy)] << endl;
	}

}