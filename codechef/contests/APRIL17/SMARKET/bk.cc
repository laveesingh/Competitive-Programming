#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

int arr[N];
unordered_map<int, int> Next, Prev;
int block;

class query{
  public:
    int l;
    int r;
    int k;
    int i;
};


bool comp(query a, query b){
  if(a.l/block == b.l/block)
    return a.r < b.r;
  return a.l < b.l;
}

inline int next(int i){
  return Next[i];
}

inline int prev(int i){
  return Prev[i];
}

int main(void){
  ios::sync_with_stdio(false);
  int t, n, q, x, y, z;
  //cin >> t;
  scanf("%d", &t);
  while(t--){
    //cin >> n >> q;
    scanf("%d %d", &n, &q);
    block = sqrt(n);
    if(block < 1) block = 1;
    for(int i = 0; i < n; i += 1)
      scanf("%d", &arr[i]);
      //cin >> arr[i];
    vector<pair<int, int> > lengths;
    int curi = 0;
    for(int i = 1; i < n; i += 1){
      if(arr[curi] != arr[i]){
        lengths.push_back({curi, i-1});
        curi = i;
      }else{
        // do nothing
      }
      if(i==n-1)
        lengths.push_back({curi, i});
    }
    for(pair<int, int> val: lengths){
      Next[val.first] = val.second;
      Prev[val.second] = val.first;
    }
    query queries[q];
    for(int i = 0; i < q; i += 1){
      //cin >> x >> y >> z;
      scanf("%d %d %d", &x, &y, &z);
      x--, y--;
      queries[i].l = x;
      queries[i].r = y;
      queries[i].k = z;
      queries[i].i = i;
    }
    sort(queries, queries+q, comp);
    int l, r, L = 0, R = 0;
    //multiset<int> mst;
    map<int, int> mst;
    map<int, int>::iterator it;
    int left_len = 0, right_len = 0;
    int ans[q];
    for(int i = 0; i < q; i += 1){
      l = queries[i].l, r = queries[i].r;
      while(R <= r){
        if(R == 0 or arr[R-1] == arr[R]){
          //mst.erase(right_len);// erases all copies of right_len
          it = mst.find(right_len);
          if(it != mst.end()){
            if(it->second == 0 or it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          right_len++;
          //mst.insert(right_len); 
          mst[right_len]++;
          R++;
        }else{
          right_len = 1;
          //mst.insert(right_len);
          mst[right_len]++;
          R++;
        }
        if(R-L == right_len)
          left_len = right_len;
      }
      while(L > l){
        if(arr[L] == arr[L-1]){
          //mst.erase(left_len);
          it = mst.find(left_len);
          if(it != mst.end()){
            if(it->second == 0 or it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          left_len++;
          //mst.insert(left_len);
          mst[left_len]++;
          L--;
        }else{
          left_len = 1;
          //mst.insert(left_len);
          mst[left_len]++;
          L--;
        }
        if(R-L == left_len) right_len = left_len;
      }
      while(L < l){
        if(R <= L){
          L++;
          continue;
        }
        if(left_len > 1){
          //mst.erase(left_len);
          it = mst.find(left_len);
          if(it != mst.end()){
            if(it->second == 0 or it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          left_len--;
          //mst.insert(left_len);
          mst[left_len]++;
          L++;
        }else{
          // ignoring case where left_len == 0
          //mst.erase(left_len);
          it = mst.find(left_len);
          if(it != mst.end()){
            if(it->second == 0 and it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          L++;
          left_len = min(R-L, next(L)-L+1);
          if(left_len < 0) left_len = 0;
        }
        if(R-L == left_len) right_len = left_len;
      }
      while(R > r+1){
        if(right_len > 1){
          //mst.erase(right_len);
          it = mst.find(right_len);
          if(it != mst.end()){
            if(it->second == 0 and it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          right_len--;
          //mst.insert(right_len);
          mst[right_len]++;
          R--;
        }else{
          // ignoring case if right_len == 0
          //mst.erase(right_len);
          it = mst.find(right_len);
          if(it != mst.end()){
            if(it->second == 0 or it->second == 1)
              mst.erase(it);
            else
              it->second = it->second-1;
          }
          right_len = (R-1) - (R>=2 ? prev(R-2) : 0);
          right_len = min(right_len, R-L-1);
          R--;
        }
        if(R-L == right_len) left_len = right_len;
      }
      //ans[queries[i].i] = distance(mst.lower_bound(queries[i].k), mst.end());
      ans[queries[i].i] = 0;
      it = mst.lower_bound(queries[i].k);
      while(it != mst.end()){
        ans[queries[i].i] += it->second;
        it++;
      }
    }
    for(int i = 0; i < q; i += 1)
      printf("%d\n", ans[i]);
      //cout << ans[i] << endl;
  }
}
