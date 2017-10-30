#include <bits/stdc++.h>

using namespace std;

class Node{
  public:
    int op, cl, to;
    
    Node(){
      op = 0, cl = 0, to = 0;
    } 

    Node(int a, int b, int c){
      op = a;
      cl = b;
      to = c;
    }
  
};

const int N = 1e6 + 1;
Node tree[4*N+4];
int n;
//string arr;
char arr[N];

Node combine(Node first, Node second){
  int t = min(first.op, second.cl);
  int op = first.op + second.op - t;
  int cl = first.cl + second.cl - t;
  int to = first.to + second.to + t;
  //cerr << "Returning " << op << "," << cl << "," << endl;
  return Node(op, cl, to);
}

void build(int node, int st, int en){
  if(st == en){
    tree[node].op = (arr[st] == '(' ? 1 : 0);
    tree[node].cl = (arr[st] == ')' ? 1 : 0);
    tree[node].to = 0;
    //cerr << "Node " << tree[node].op << "," << tree[node].cl << "," << tree[node].to << endl;
  }else{
    int mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid+1, en);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
  }
}

Node query(int node, int st, int en, int i, int j){
  if(i <= st and en <= j){
    return tree[node];
  }else{
    int mid = (st + en)/2;
    if(i > en or j < st or st > en) return Node(0, 0, 0);
    Node first = query(2*node, st, mid, i, j);
    Node second = query(2*node+1, mid+1, en, i, j);
    return combine(first, second);
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  //cin >> arr;
  scanf("%s", arr);
  //n = arr.length();
  n = strlen(arr);
  build(1, 0, n-1);
  int m, i, j;
  //cin >> m;
  scanf("%d", &m);
  while(m--){
    //cin >> i >> j;
    scanf("%d %d", &i, &j);
    i--, j--;
    Node ans = query(1, 0, n-1, i, j);
    //cout << (ans.to)*2 << endl;
    printf("%d\n", (ans.to)*2);
  }
}

