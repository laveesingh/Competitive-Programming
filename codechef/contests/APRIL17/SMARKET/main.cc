#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e5+1;
//const int block = 350;

int arr[N];
unordered_map<int, int> Next, Prev;
int block;

/////////////////// /////////////////// ///////////////////

#define height(node) (node==NULL ? 0 : node->height)

class Node{
  public:
    int key, height, stsize;
    Node *left, *right;
    Node* left_rotate();
    Node* right_rotate();
    Node* min_node();
};

int subtree(Node* node){
  if(node == NULL)
    return 0;
  node->stsize = 1 + subtree(node->left) + subtree(node->right);
  return node->stsize;
}

Node* Node::left_rotate(){
  //cout << "In: left rotate" << endl;
  Node* y = this->right;
  if(y == NULL) return this;
  Node* T = y->left;
  y->left = this;
  this->right = T;
  subtree(this);
  subtree(y);
  this->height = max(height(this->left), height(this->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  //cout << "Out: left rotate" << endl;
  return y;
}

Node* Node::right_rotate(){
  //cout << "In: right rotate" << endl;
  Node* x = this->left;
  //cout << "First" << endl;
  if(x == NULL) return this;
  Node* T = x->right;
  //cout << "Second" << endl;
  x->right = this;
  //cout << "Third" << endl;
  this->left = T;
  //cout << "Setting subtrees" << endl;
  subtree(this);
  subtree(x);
  this->height = max(height(this->left), height(this->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  //cout << "Out: right rotate" << endl;
  return x;
}

Node* Node::min_node(){
  if(this->left == NULL) return this;
  return this->left->min_node();
}

int get_balance(Node* node){
  if(node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

Node* newNode(int k){
  Node *temp = new Node;
  temp->key = k;
  temp->height = 1;
  temp->left = NULL;
  temp->right = NULL;
  temp->stsize = 1;
  return temp;
}

class AVL{
  public:
    Node *root = NULL;

    void init(int rootkey){
      root = newNode(rootkey);
    }

    Node* insert(Node* node, int key){
      if(node == NULL)
        return newNode(key);
      if(key < node->key)
        node->left = insert(node->left ,key);
      else
        node->right = insert(node->right, key);
      //cout << "Going to maintain heights"  << endl;
      node->height = max(height(node->left), height(node->right)) + 1; // I think this should be after rotations
      //cout << "Maintained heights" << endl;
      int balance = get_balance(node);
      if(balance > 1 and key < node->left->key)
        return node->right_rotate();
      if(balance < -1 and key > node->right->key)
        return node->left_rotate();
      if(balance > 1 and key > node->left->key){
        node->left = node->left->left_rotate();
        return node->right_rotate();
      }
      if(balance < -1 and key < node->right->key){
        node->right = node->right->right_rotate();
        return node->left_rotate();
      }
      subtree(node);
      return node;
    }

    Node* insert(int key){
      cerr << "Getting into insert " << key << endl;
      root = insert(root, key);
      cerr << "Getting out of insert " << key << endl;
    }

    Node* erase(Node* node, int key){
      if(node == NULL)
        return node;
      if(key < node->key)
        node->left = erase(node->left, key);
      else if(key > node->key)
        node->right = erase(node->right, key);
      else{
        if(node->left == NULL or node->right == NULL){
          Node* temp = node->left ? node->left : node->right;
          if(temp == NULL){
            temp = node;
            node = NULL;
          }else{
            *node = *temp;
          }
          free(temp);
        }else{
          //Node* temp = min_node(node->right);
          Node* temp = node->right->min_node();
          node->key = temp->key;
          node->right = erase(node->right, temp->key);
        }
      }
      if(node == NULL)
        return node;
      node->height = max(height(node->left), height(node->right)) + 1;
      //int balance = node->left->height - node->right->height;
      int balance = get_balance(node);
      if(balance > 1 and get_balance(node->left) >= 0)
        return node->right_rotate();
      if(balance < -1 and get_balance(node->right) <= 0)
        return node->left_rotate();
      if(balance > 1 and get_balance(node->left) < 0){
        node->left = node->left->left_rotate();
        return node->right_rotate();
      }
      if(balance < -1 and get_balance(node->right) > 0){
        node->right = node->right->right_rotate();
        return node->left_rotate();
      }
      subtree(node);
      return node;
    }

    Node* erase(int key){
      cerr << "Entering into deletion" << endl;
      root = erase(root, key);
      cerr << "Getting out of deletion deletion" << endl;
    }

    int __ge__(Node* node, int key){
      if(node == NULL)
        return 0;
      //if(node->key == key)
        //return 1 + (node->right ? node->right->stsize : 0);
      if(key <= node->key)
        return 1+ (node->right ? node->right->stsize: 0) + __ge__(node->left, key);
      if(key > node->key)
        return __ge__(node->right, key);
    }

    int __ge__(int key){
      return __ge__(root, key);
    }

    void inorder(Node* node){
      if(node != NULL){
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
      }
    }

    void inorder(){
      inorder(root);
    }

};

/////////////////// /////////////////// ///////////////////

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
  cin >> t;
  while(t--){
    cin >> n >> q;
    block = sqrt(n);
    //block = 500;
    if(block < 1) block = 1;
    for(int i = 0; i < n; i += 1)
      cin >> arr[i];
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
      cin >> x >> y >> z;
      x--, y--;
      queries[i].l = x;
      queries[i].r = y;
      queries[i].k = z;
      queries[i].i = i;
    }
    sort(queries, queries+q, comp);
    int l, r, L = 0, R = 0;
    AVL mst;
    //struct Node* root = NULL;
    int left_len = 0, right_len = 0;
    int ans[q];
    for(int i = 0; i < q; i += 1){
      l = queries[i].l, r = queries[i].r;
      while(R <= r){
        if(R == 0 or arr[R-1] == arr[R]){
          mst.erase(right_len);
          //root = deleteNode(root, right_len);
          right_len++;
          mst.insert(right_len); 
          //root = insert(root, right_len);
          R++;
        }else{
          right_len = 1;
          mst.insert(right_len);
          //root = insert(root, right_len);
          R++;
        }
        if(R-L == right_len)
          left_len = right_len;
      }
      while(L > l){
        if(arr[L] == arr[L-1]){
          mst.erase(left_len);
          //root = deleteNode(root, left_len);
          left_len++;
          mst.insert(left_len);
          //root = insert(root, left_len);
          L--;
        }else{
          left_len = 1;
          mst.insert(left_len);
          //root = insert(root, left_len);
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
          mst.erase(left_len);
          //root = deleteNode(root, left_len);
          left_len--;
          mst.insert(left_len);
          //root = insert(root, left_len);
          L++;
        }else{
          mst.erase(left_len);
          //root = deleteNode(root, left_len);
          L++;
          left_len = min(R-L, next(L)-L+1);
          if(left_len < 0) left_len = 0;
        }
        if(R-L == left_len) right_len = left_len;
      }
      while(R > r+1){
        if(right_len > 1){
          mst.erase(right_len);
          //root = deleteNode(root, right_len);
          right_len--;
          mst.insert(right_len);
          //root = insert(root, right_len);
          R--;
        }else{
          // ignoring case if right_len == 0
          mst.erase(right_len);
          //root = deleteNode(root, right_len);
          right_len = (R-1) - (R>=2 ? prev(R-2) : 0);
          right_len = min(right_len, R-L-1);
          R--;
        }
        if(R-L == right_len) left_len = right_len;
      }
      ans[queries[i].i] = mst.__ge__(queries[i].k);
      //ans[queries[i].i] = greaters(root, queries[i].k);
    }
    for(int i = 0; i < q; i += 1)
      cout << ans[i] << endl;
  }
}
