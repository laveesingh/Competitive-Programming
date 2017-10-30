#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
pair<int, int> points[N];

bool comp(pair<int, int> a, pair<int, int> b){
  int dist1 = a.first * a.first + a.second * a.second;
  int dist2 = b.first * b.first + b.second * b.second;
  return dist1 < dist2;
}

int main(void){
  int n, x, y;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    points[i] = {x, y};
  }
  sort(points, points+n, comp);
  vector<string> cmds;
  for(int i = 0; i < n; i++){
    x = points[i].first;
    y = points[i].second;
    if(x == 0){
      if(y > 0){
        string cmd = "1 " + to_string(y) + " U";
        string cmd1 = "1 " + to_string(y) + " D";
        cmds.push_back(cmd);
        cmds.push_back("2");
        cmds.push_back(cmd1);
        cmds.push_back("3");
      } else if(y < 0){
        string cmd = "1 " + to_string(abs(y)) + " D";
        string cmd1 = "1 " + to_string(abs(y)) + " U";
        cmds.push_back(cmd);
        cmds.push_back("2");
        cmds.push_back(cmd1);
        cmds.push_back("3");
      }
    } else if(y == 0){
      if(x > 0){
        string cmd = "1 " + to_string(x) + " R";
        string cmd1 = "1 " + to_string(x) + " L";
        cmds.push_back(cmd);
        cmds.push_back("2");
        cmds.push_back(cmd1);
        cmds.push_back("3");
      } else if(x < 0){
        string cmd = "1 " + to_string(abs(x)) + " L";
        string cmd1 = "1 " + to_string(abs(x)) + " R";
        cmds.push_back(cmd);
        cmds.push_back("2");
        cmds.push_back(cmd1);
        cmds.push_back("3");
      }
    } else{
      string cmd1 = "1 " + to_string(abs(x)) + (x > 0 ? " R" : " L");
      string cmd2 = "1 " + to_string(abs(x)) + (x > 0 ? " L" : " R");
      string cmd3 = "1 " + to_string(abs(y)) + (y > 0 ? " U" : " D");
      string cmd4 = "1 " + to_string(abs(y)) + (y > 0 ? " D" : " U");
      cmds.push_back(cmd1);
      cmds.push_back(cmd3);
      cmds.push_back("2");
      cmds.push_back(cmd2);
      cmds.push_back(cmd4);
      cmds.push_back("3");
    }
  }
  cout << cmds.size() << endl;
  for(string cmd: cmds) cout << cmd << endl;
}
