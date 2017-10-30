#include <iostream>
using namespace std;

const int N = 3e4 + 1;
const int BLOCK = 200;

class query{
  public:
    int i, j, k, index, answer;
    query(int index, int i, int j, int k){
      index = index;
      i = i;
      j = j;
      k = k;
      answer = 0;
    }
}
// something

bool comp(const query& first, const query& second){
  int fblock = first.i / BLOCK,
      sblock = second.i / BLOCK;
  if(fblock == sblock)
    return first.j  < second.j;
  return fblock < sblock;
}

bool comp_ind(const query& first, const query& second){
  return first.i < second.i;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, x, y, z;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    query queries[q];
    for(int i = 0; i < q; i++){
      cin >> x >> y >> z;
      queries[i] = query(i, x, y, z);
    }
    sort(queries, queries+q, comp);
    int l = 0, r = 0;
    for(int i = 0; i < q; i++){
      int L = queries[i].
    }

}
