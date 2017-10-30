#include <bits/stdc++.h>

using namespace std;

class BIT{
  public:
    vector<long long> tree;
    void build(long long n){
      tree = vector<long long> (n, 0);
    }
    void add(long long i, long long val){
      while(i < tree.size()){
        tree[i] += val;
        i += (i & -i);
      }
    }
    long long get_sum(long long i){
      long long ans = 0;
      while(i > 0){
        ans += tree[i];
        i -= (i & -i);
      }
      return ans;
    }
    long long size(){
      return tree.size();
    }
    void print(){
      cerr << "BIT: ";
      for(long long i : tree) cerr << i << " ";
      cerr << endl;
    }
};

BIT tree;
unordered_set<long long> tset;

void insert(long long val){
  if(tset.find(val) != tset.end()) return;
  tree.add(val, 1);
  tset.insert(val);
}

void erase(long long val){
  if(tset.find(val) == tset.end()) return;
  tree.add(val, -1);
  tset.erase(val);
}

long long kth_smallest(long long k){
  long long lo = 0, hi = tree.size()-1;
  long long mid = -1;
  while(lo < hi){
    mid = (lo + hi)/2;
    if(k <= tree.get_sum(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  //cerr << "sum up to " << lo << " is " << tree.get_sum(lo) << endl;
  if(tree.get_sum(lo) < k) return -1;
  return lo;
}

long long Rank(long long n){
  return tree.get_sum(n-1);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  char op[n];
  long long val[n];
  for(long long i = 0; i < n; i++)
    cin >> op[i] >> val[i];
  vector<long long> orig(val, val+n);
  sort(val, val+n);
  unordered_map<long long, long long> value, reval;
  long long cur = 1;
  value[val[0]] = cur;
  reval[cur] = val[0];
  for(long long i = 1; i < n; i++){
    if(val[i] == val[i-1]) continue;
    else {
      value[val[i]] = ++cur;
      reval[cur] = val[i];
    }
  }
  for(long long i = 0; i < n; i++) orig[i] = value[orig[i]];
  //for(long long i = 0; i < n; i++) cerr << orig[i] << endl;
  tree.build(n+2);
  for(long long i = 0; i < n; i++){
    if(op[i] == 'I'){
      //cerr << "inserting: " << orig[i] << endl;
      insert(orig[i]);
    }else if(op[i] == 'D'){
      //cerr << "deleting: " << orig[i] << endl;
      erase(orig[i]);
    }else if(op[i] == 'K'){
      long long ans = kth_smallest(reval[orig[i]]);
      //cerr << "Kth: " << reval[orig[i]] << endl;
      if(ans == -1) cout << "invalid" << endl;
      else cout << reval[ans] << endl;
    }else{
      long long ans = Rank(orig[i]);
      //cerr << "Count" << endl;
      cout << ans << endl;
    }
    //tree.prlong long();
  }
}
