#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long N = 1e5 + 1;
const long long X = 1e6 + 1;

vector<long long> tree[4*N + 5];
long long arr[N];
long long spf[X];


void set_smallest_prime_factor(){
  for(long long i = 0; i < X; i += 1)
    spf[i] = i%2 ? i : 2;
  for(long long i = 3; i < X; i += 2) if(spf[i] == i)
      for(long long j = i; j < X; j += i)
        spf[j] = min(spf[j], i);
}

vector<long long> prime_factors(long long n){
    vector<long long> ret;
    while(n > 1){
        ret.push_back(spf[n]);
        n /= spf[n];
    }
    return move(ret);
}

vector<long long> merge_sorted(const vector<long long>& vfirst, const vector<long long>& vsecond){
    vector<long long> ret;
    long long i = 0, j = 0;
    while(i < vfirst.size() || j < vsecond.size()){
        if(i >= vfirst.size()){
            while(j < vsecond.size())
                ret.push_back(vsecond[j]), j++;
            break;
        }
        if(j >= vsecond.size()){
            while(i < vfirst.size()){
                ret.push_back(vfirst[i]), i++;
            }
            break;
        }
        if(vfirst[i] <= vsecond[j])
            ret.push_back(vfirst[i]), i++;
        else
            ret.push_back(vsecond[j]), j++;
    }
    return move(ret);
}

void build(long long node, long long start, long long end){
    if(start == end){
        tree[node] = prime_factors(arr[start]);
    }else{
        long long mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node + 1, mid+1, end);
        tree[node] = merge_sorted(tree[2*node], tree[2*node+1]);
    }
}

long long query(long long node, long long start, long long end, long long a, long long b, long long x, long long y){
    if(a <= start && end <= b){
        long long start_index = lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();;
        long long end_index = upper_bound(tree[node].begin(), tree[node].end(), y) - tree[node].begin();
        return (end_index - start_index);
    }else if(start > b || end < a || start > end){
        return 0;
    }else{
        long long mid = (start + end)/2;
        long long first = query(2*node, start, mid, a, b, x, y);
        long long second = query(2*node+1, mid+1, end, a, b, x, y);
        return first + second;
    }
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set_smallest_prime_factor();
    long long n, a, b, x, y, q;
    cin >> n;
    for(long long i = 0; i < n; i += 1){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    cin >> q;
    for(long long i = 0; i < q; i += 1){
        cin >> a >> b >> x >> y;
        a--, b--;
        cout << query(1, 0, n-1, a, b, x, y) << endl;
    }
}