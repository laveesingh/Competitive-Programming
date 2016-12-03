// given a string and delimiter, splits and returns a vector of strings
inline vector<string> split(const string& s, const char& c){
	vector<string> ret;
	stringstream ss(s);
	string x;
	while(getline(ss, x, c))
		ret.emplace_back(x);
	return move(ret);
}
