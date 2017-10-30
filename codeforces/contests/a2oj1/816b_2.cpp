#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 1;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, q, x, y;
  cin >> n >> k >> q;
  int freq[N];
  fill_n(freq, N, 0);
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    freq[x]++, freq[y+1]--;
  }
  for(int i = 1; i < N; i++) freq[i] += freq[i-1];
  //for(int i = 85; i <= 105; i++) cerr << i << ": " << freq[i] << endl;
  for(int i = 0; i < N; i++) freq[i] = (freq[i] < k ? 0 : 1);
  for(int i = 1; i < N; i++) freq[i] += freq[i-1];
  for(int i = 0; i < q; i++){
    cin >> x >> y;
    //cerr << freq[y] << " - " << freq[x-1] << endl;
    cout << (freq[y] - freq[x-1]) << endl;
  }
}

