#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define pii pair<long long, long long> 
const long long N = 1e5 + 1;
long long n;
long long arr[N], tray[N];
long long tree[4*N + 4];

void build(long long node, long long st, long long en){
  if(st == en){
    tree[node] = 1;
  }else{
    long long mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node] = tree[2*node] + tree[2*node+1];
  }
}

void update(long long node, long long st, long long en, long long ind){
  if(st == en && st == ind){
    tree[node] = 0;
  }else{
    long long mid = (st+en)/2;
    if(en < ind || st > ind || en < st) return ;
    update(2*node, st, mid, ind);
    update(2*node+1, mid+1, en, ind);
    tree[node] = tree[2*node] + tree[2*node+1];
  }
}

long long query(long long node, long long st, long long en, long long i, long long j){
  if(i <= st && en <= j) return tree[node];
  if(i > en || j < st || st > en) return 0;
  long long mid = (st + en)/2;
  return query(2*node, st, mid, i, j) + query(2*node+1, mid+1, en, i, j);
}

int main(void){
  cin >> n;
  for(long long i = 0; i < n; i++) cin >> arr[i];
  build(1, 0, n-1);
  map<long long, vector<long long> > inds;
  for(long long i = 0; i < n; i++) inds[arr[i]].push_back(i);
  long long p = 0, ans = 0;
  while(!inds.empty()){
    vector<long long> cur = inds.begin() -> second;
    //cerr << "Found " << (inds.begin() -> first) << endl;
    inds.erase(inds.begin());
    long long last_ind = cur.back();
    long long first_ind = cur.front();
    if(first_ind >= p){
      //cerr << "p is " << p << " and first_ind is " << first_ind << endl;
      ans += query(1, 0, n-1, p, last_ind);
      for(long long s: cur) update(1, 0, n-1, s);
      p = last_ind;
    }else{
      long long max_prev = -1;
      for(long long s: cur)
        if(s < p && s > max_prev) max_prev = s;
      //cerr << "p is " << p << " and max_prev is " << max_prev << endl;
      ans += query(1, 0, n-1, p, n-1) + query(1, 0, n-1, 0, max_prev);
      for(long long s: cur) update(1, 0, n-1, s);
      p = max_prev;
    }
  }
  cout << ans << endl;
}
