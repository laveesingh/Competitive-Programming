#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

class operation{
public:
	string statement;
	int num;
	operation(){}
	operation(string s, int n=0){
		statement = s;
		num = 	n;
	}
};
int main(void){
	int n;
	// cin >> n;
	scanf("%d", &n);
	string name;
	int num;
	operation a[n];
	char nametemp[100];
	// for(int test = 0; test < n; test += 1){
	// 	// cin >> name;
	// 	scanf("%s", nametemp);
	// 	name = nametemp;
	// 	if(name=="removeMin"){
	// 		a[test] = operation(name);
	// 	}else{
	// 		// cin >> num;
	// 		scanf("%d", &num);
	// 		a[test] = operation(name, num);
	// 	}
	// }
	// cout << "Input taken" << endl;
	vector<operation> output;
	multiset<int> curmin;
	multiset<int>::iterator it, it2;
	for(int i = 0; i < n; i += 1){
		scanf("%s", nametemp);
		name = nametemp;
		if(name != "removeMin"){
			scanf("%d", &num);
		}
		if(name == "insert"){
			output.push_back(operation(name, num));
			curmin.insert(num);
		}else if(name == "removeMin"){
			output.push_back(operation(name));
			it = curmin.begin();
			it2 = it;
			it2++;
			curmin.erase(it, it2);
		}else{
			// cout << "Entering the last condition" << endl;
			int minimum = num;
			it = curmin.begin();
			while(!curmin.empty() && *(curmin.begin()) < minimum){
				// cout << "WHile" << endl;
				// if(!curmin.empty() && *(it) >= minimum) break;
				operation temp;
				temp.statement="removeMin";
				output.push_back(temp);
				it = curmin.begin();
				it2 = it;
				it2++;
				// cout << "BEfore erase" << endl;
				if(curmin.size() < 2){
					curmin.clear();
					break;
				}else{
					curmin.erase(it, it2);
				}
				// cout << "After earase " << endl;
			}
			// cout << "Out of while loop" << endl;
			if(curmin.empty() || *(curmin.begin())>minimum){
				curmin.insert(minimum);
				operation temp;
				temp.statement = "insert";
				temp.num = minimum;
				output.push_back(temp);
			}
			output.push_back(operation("getMin", num));
		}
	}
	cout << output.size() << endl;
	char tempname[100];
	for (int i = 0; i < output.size(); i += 1){
		// tempname = output[i].statement;
		if(output[i].statement == "removeMin"){
			// cout << output[i].statement << endl;
			printf("%s\n", output[i].statement.c_str());
		}else{
			// cout << output[i].statement << " " << output[i].num << endl;
			printf("%s %d\n", output[i].statement.c_str(), output[i].num);
		}
	}
}