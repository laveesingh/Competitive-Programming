#include <iostream>
#include <map>
#include <cstring>

using namespace std;

inline bool isvalid(int i, int j, int n){
  return (i >= 0 and j >= 0 and i < n and j < n);
}


int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, l;
  string cmd;
  cin >> t;
  while(t--){
    cin >> l >> n;
    cin >> cmd;
    string grid[n];
    bool all_empty = true;
    for(int i = 0; i < n; i += 1){
      cin >> grid[i];
      for(int j = 0; j < n; j += 1)
        all_empty &= (grid[i][j] == '.');
    }
    map<int, int> U, D, R, L;
    int seq[l];
    memset(seq, 0, sizeof(seq));
    int cur_move = 0;
    for(int i = 0; i < l; i++){
      if(cmd[i] == 'D')
        seq[i] = ++cur_move;
      else if(cmd[i] == 'U')
        seq[i] = --cur_move;
    }
    for(int i = 0; i < l; i++){
      if(!D[seq[i]])
        D[seq[i]] = i+1;
    }

    cur_move = 0;
    memset(seq, 0, sizeof(seq));
    for(int i = 0; i < l; i++){
      if(cmd[i] == 'R')
        seq[i] = ++cur_move;
      else if(cmd[i] == 'L')
        seq[i] = --cur_move;
    }
    for(int i = 0; i < l; i++){
      if(!R[seq[i]])
        R[seq[i]] = i+1;
    }
    int ans = 0;
    int posd, posu, posr, posl;
    //cerr << "D map " << endl;
    //for(pair<int, int> val: D)
      //cerr << val.first << ": " << val.second << endl;
    //cerr << "R map " << endl;
    //for(pair<int, int> val: R)
      //cerr << val.first << ": " << val.second << endl;

    if(all_empty){
      for(int i = 0; i < n; i += 1){
        for(int j = 0; j < n; j += 1){
          int moves = l;
          posd = n-i;
          moves = min(moves, (D[posd]==0?l+1:D[posd])-1);
          posu = i+1;
          moves = min(moves, (D[-posu]==0?l+1:D[-posu])-1);
          posr = n-j;
          moves = min(moves, (R[posr]==0?l+1:R[posr])-1);
          posl = j+1;
          moves = min(moves, (R[-posl]==0?l+1:R[-posl])-1);
          //cerr << moves << " ";
          ans ^= moves;
        }
        //cerr << endl;
      }
      cout << ans << endl;
      continue;
    }

    for(int i = 0; i < n; i += 1){
      for(int j = 0; j < n; j += 1){
        //cerr << "Checking for " << i << " " << j << endl;
        int moves = 0;
        int curi = i, curj = j;
        while(moves < l and isvalid(curi, curj, n)and grid[curi][curj] != '#'){
          if(cmd[moves] == 'D')
            curi++;
          else if(cmd[moves] == 'U')
            curi--;
          else if(cmd[moves] == 'R')
            curj++;
          else
            curj--;
          if (isvalid(curi, curj, n) and grid[curi][curj] != '#')
            moves++;
        }
        //cerr << "moves: " << moves << endl;
        ans ^= moves;
      }
    }
    cout << ans << endl;
  }
}
