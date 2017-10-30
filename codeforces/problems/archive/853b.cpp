#include <bits/stdc++.h>

using namespace std;

class flight{
  public:
    long long day, from, to, cost;
    flight(){}
    flight(long long d, long long f, long long t, long long c){
      day = d;
      from = f;
      to = t;
      cost = c;
    }
    bool operator <(const flight& other){
      return day < other.day;
    }
};

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, di, fi, ti, ci;
  cin >> n >> m >> k;
  flight flights[m];
  for(long long i =0; i < m; i++){
    cin >> di >> fi >> ti >> ci;
    flights[i] = flight(di, fi, ti, ci);
  }
  sort(flights, flights+m);
  long long init = -1, fin = -1;
  set<long long> reached;
  // first find initial polong long till when all juries can be called
  for(long long i = 0; i < m; i++){
    if(flights[i].from == 0) continue;
    reached.insert(flights[i].from);
    if(reached.size() == n) {
      init = i;
      break;
    }
  }
  reached.clear();
  // then find last polong long when juries can be started to send back
  for(long long i = m-1; i >= 0; i--){
    if(flights[i].to == 0) continue;
    reached.insert(flights[i].to);
    if(reached.size() == n) {
      fin = i;
      break;
    }
  }
  reached.clear();
  // check for conditions where it's impossible
  if(init == -1 or fin == -1){
    cout << -1 << endl;
    return 0;
  }
  if(flights[fin].day - flights[init].day < k+1){
    cout << -1 << endl;
    return 0;
  }
  //cerr << "Initial polong long: " << init << " final polong long: " << fin << endl;
  long long icost[n+1], fcost[n+1];

  // apply greedy and try to minimize calling cost
  fill_n(icost, n+1, 1e9);
  for(long long i = 0; i <= init; i++){
    long long orig = flights[i].from;
    icost[orig] = min(icost[orig], flights[i].cost);
  }

  // apply greedy and try to minimize sending cost
  fill_n(fcost, n+1, 1e9);
  for(long long i = m-1; i >= fin; i--){
    long long dest = flights[i].to;
    fcost[dest] = min(fcost[dest], flights[i].cost);
  }

  // find current total cost of calling and sending juries
  long long call_cost = 0, send_cost = 0;
  for(long long i = 1; i <= n; i++) call_cost += icost[i];
  for(long long i = 1; i <= n; i++) send_cost += fcost[i];
  //cerr << "Callcost: " << call_cost << " send_cost : " << send_cost << endl;

  long long min_init[m], min_fin[m];
  fill_n(min_init, m, 1e9);
  fill_n(min_fin, m, 1e9);
  long long min_cost = call_cost + send_cost;
  // apply greedy and extend the relaxation of minimal calling and sending costs
  min_init[init] = call_cost;
  for(long long i = init+1; i < fin; i++){
    long long city = flights[i].from;
    if(city != 0 and icost[city] > flights[i].cost){
      min_init[i] = min_init[i-1] + flights[i].cost - icost[city];
      icost[city] = flights[i].cost;
    }else{
      min_init[i] = min_init[i-1];
    }
  }
  min_fin[fin] = send_cost;
  for(long long i = fin-1; i > init; i--){
    long long city = flights[i].to;
    if(city != 0 and fcost[city] > flights[i].cost){
      min_fin[i] = min_fin[i+1] + flights[i].cost - fcost[city];
      fcost[city] = flights[i].cost;
    }else{
      min_fin[i] = min_fin[i+1];
    }
  }
  for(long long i = init; i < fin; i++){
    long long cday = flights[i].day;
    long long ind = lower_bound(flights+i, flights+fin, flight(cday+k+1, 1, 1, 1)) - flights;
    if(ind <= fin){
      min_cost  = min(min_cost, min_init[i]+min_fin[ind]);
    }
  }
  cout << min_cost << endl;
}

