
class BIT{
  public:
    vector<int> tree;
    BIT(int n){
      tree = vector<int>(n);
    }
    void add(int i, int val){
      while(i < tree.size()){
        tree[i] += val;
        i += (i & -i);
      }
    }
    int get_sum(int i){
      int ans = 0;
      while(i > 0){
        ans += tree[i];
        i -= (i & -i);
      }
      return ans;
    }
};
