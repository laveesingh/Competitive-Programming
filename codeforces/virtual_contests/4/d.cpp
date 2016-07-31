#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

#define pii pair<int, int>
#define piii pair<pii, int>
#define mp make_pair
#define pb push_back

bool comp(piii a, piii b){
	// return a.first*a.second <= b.first*b.second;
	return a.first.first <= b.first.first;
}

bool issmaller(piii a, piii b){
	// cout << a.first.first << " is smaller than " << b.first.first << " and " << a.first.second << " is smaller than " << b.first.second << endl;
	if (a.first.first < b.first.first && a.first.second < b.first.second) {
		// cout << a.first.first << " is smaller than " << b.first.first << " and " << a.first.second << " is smaller than " << b.first.second << endl;
		return true;
	}
	return false;
}

int main(void){
	int n, w, h, wi, hi;
	cin >> n >> w >> h;
	piii envelope[n];
	for (int i = 0; i < n ; i += 1){
		cin >> wi >> hi;
		envelope[i] = mp(mp(wi,hi),i);
	}
	vector<piii> valid_envelope;
	piii card = mp(mp(w,h), 0);
	for (int i = 0; i < n; i += 1){
		if (issmaller(card, envelope[i])){
			// cout << "Card : " << card.first.first << " " << card.first.second  << " is smaller than envelope[i] : " << envelope[i].first.first << " "<< envelope[i].first.second << endl;
			valid_envelope.pb(envelope[i]);
		}
	}
	sort(valid_envelope.begin(), valid_envelope.end(), comp);
	// cout << "Here are the sorted envelopes" << endl;
	// for (int i = 0; i < valid_envelope.size(); i += 1){
	// 	cout << valid_envelope[i].first.first << " " << valid_envelope[i].first.second << " " << valid_envelope[i].second+1 << endl;
	// }
	int no = valid_envelope.size();
	// cout << "Valid envelope " << valid_envelope[0].first.first << " " << valid_envelope[0].first.second << " " << valid_envelope[0].second<< endl;
	if(no == 0){
		cout << 0 << endl;
	}else if(no == 1){
		// cout << 1 << endl << 1 << endl;
		cout << 1 << endl << valid_envelope[0].second+1 << endl;
	}else{
		int dp[no+1];
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= no; i += 1){
			dp[i] = 1;
			for (int j = 1; j < i; j += 1){
				if(issmaller(valid_envelope[j-1], valid_envelope[i-1])){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		// cout << "Here is the dp table: " << endl;
		// for (int i = 0; i <= no; i += 1){
		// 	cout << dp[i] << " ";
		// }
		// cout << endl;
		int maxelem_index = max_element(dp, dp+no+1)-dp;
		deque<piii> finals;
		// cout << "Maximum index is : " << maxelem_index << endl;
		// cout << "Pushing: " << valid_envelope[maxelem_index-1].first.first << " " << valid_envelope[maxelem_index-1].first.second << endl;
		finals.push_front(valid_envelope[maxelem_index-1]);
		int last_used_index = maxelem_index;
		while(maxelem_index > 1){
			maxelem_index -= 1;
			if(issmaller(valid_envelope[maxelem_index-1], valid_envelope[last_used_index-1]) && dp[maxelem_index]==dp[last_used_index]-1){
				finals.push_front(valid_envelope[maxelem_index-1]);
				// cout << "Pushing: " << valid_envelope[maxelem_index-1].first.first << " " << valid_envelope[maxelem_index-1].first.second << endl;
				last_used_index = maxelem_index;
			}
		}
		cout << finals.size() << endl;
		for (deque<piii>::iterator it = finals.begin(); it != finals.end(); it++){
			piii cur = *it;
			cout << cur.second+1 << " ";
		}
		cout << endl;
	}
}