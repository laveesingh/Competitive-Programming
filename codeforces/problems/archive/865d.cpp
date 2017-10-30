#include <bits/stdc++.h>

using namespace std;
const long long N = 3e5 + 1;

void print(multiset<long long> a){
  for(long long i: a) cerr << i << " ";
  cerr << endl;
}

int main(void){
  multiset<long long> st;
  long long n;
  cin >> n;
  long long x, ans = 0;
  for(long long i = 0; i < n; i++){
    cin >> x;
    st.insert(-x);
    st.insert(-x);
    long long cur_max = *st.rbegin();
    //cerr << "curmax " << cur_max << "==>";
    //prlong long(st);
    ans += x + cur_max;
    auto it = st.find(*st.rbegin());
    auto it2 = it;
    ++it2;
    st.erase(it, it2);
  }
  cout << ans << endl;
}
