#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int N = 1e5 + 1;
int Day[N], Total[N], Sadness[N];

class Professor{
  public:
    int id, day, total, sadness;
    
    Professor(int _id, int _d, int _t, int _s){
      id = _id;
      day = _d;
      total = _t;
      sadness = _s;
    }

    friend bool operator <(Professor const & , Professor const&);
};

bool operator<(Professor const &first, Professor const &second){
      return first.sadness >= second.sadness;
    }

int main(void){
  int t;
  cin >> t;
  while(t--){
    int n, d;
    cin >> n >> d;
    map<int, vector<Professor> > profsOnDay;
    for(int i = 0; i < n; i++) {
      cin >> Day[i] >> Total[i] >> Sadness[i];
      profsOnDay[Day[i]].push_back( Professor(i, Day[i], Total[i], Sadness[i]) ); 
    }
    set<Professor> profsTillDay;
    for(int day = 1; day <= d; day++){
      for(Professor professor: profsOnDay[day]){ profsTillDay.insert(professor); } 
      if(profsTillDay.empty()) continue;
      Professor cur = *(profsTillDay.begin());
      //cerr << "cur: " << cur.id << " " << cur.day << " " << cur.total << " " << cur.sadness << endl;
      profsTillDay.erase(profsTillDay.begin());
      cur.total -= 1;
      if(cur.total > 0) profsTillDay.insert(cur);
    }
    long long sadness = 0ll;
    for(Professor professor: profsTillDay){
      //cerr << "professor: " << professor.id << " " << professor.day << " " << professor.total << " " << professor.sadness << endl;
      sadness += (long long) professor.sadness * professor.total;
    }
    cout << sadness << endl;
  }
}
