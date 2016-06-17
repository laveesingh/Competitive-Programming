#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;
	string name, countryname;
	map<string, string> country;
	map<string, int> points;
	map<string, int> countrypoints;
	for (int i = 0; i < n; i+=1){
		cin >> name >> countryname;
		country[name] = countryname;
	}
	for (int i = 0; i < m; i += 1){
		cin >> name;
		points[name] += 1;
		countrypoints[country[name]] += 1;
	}
	vector<string> winnerchefs;
	vector<string> winnercountries;
	int max_chef_points = 0;
	for(map<string,int>::iterator it = points.begin(); it != points.end(); it++){
		max_chef_points = max(max_chef_points, it->second);
	}
	int max_country_points = 0;
	for(map<string,int>::iterator it = countrypoints.begin(); it != countrypoints.end(); it++){
		max_country_points = max(max_country_points, it->second);
	}
	for (map<string, int>::iterator it = points.begin(); it != points.end(); it++){
		if(it->second == max_chef_points){
			winnerchefs.push_back(it->first);
		}
	}
	for (map<string, int>::iterator it = countrypoints.begin(); it != countrypoints.end(); it++){
		if(it->second == max_country_points){
			winnercountries.push_back(it->first);
		}
	}
	sort(winnerchefs.begin(), winnerchefs.end());
	sort(winnercountries.begin(), winnercountries.end());
	cout << winnercountries[0] << endl;
	cout << winnerchefs[0] << endl;
}	