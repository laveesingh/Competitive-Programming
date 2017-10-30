// C++ program to find rank of an element
// and k-th smallest element.
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_VAL = 1000001;
 
/* Updates element at index 'i' of BIT. */
void update(int i, int add, vector<int>& BIT)
{
		cerr << "updating for index: " << i << " ";
    while (i > 0 && i < BIT.size())
    {
      cerr << " then " << i;
        BIT[i] += add;
        i = i + (i & (-i));
    }
    cerr << endl;
}
 
/* Returns cumulative sum of all elements of
   fenwick tree/BIT from start upto and
   including element at index 'i'. */
int sum(int i, vector<int>& BIT)
{
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i = i - (i & (-i));
    }
 
    return ans;
}
 
// Returns lower bound for k in BIT.
int findKthSmallest(int k, vector<int> &BIT)
{
    // Do binary search in BIT[] for given
    // value k.
    int l = 0;
    int h = BIT.size();
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= sum(mid, BIT))
            h = mid;
        else
            l = mid+1;
    }
 
    return l;
}
 
// Insert x into BIT. We masically increment
// rank of all elements greater than x.
void insertElement(int x, vector<int> &BIT)
{
    update(x, 1, BIT);
}
 
// Delete x from BIT. We masically decreases
// rank of all elements greater than x.
void deleteElement(int x, vector<int> &BIT)
{
    update(x, -1, BIT);
}
 
// Returns rank of element. We basically
// return sum of elements from start to
// index x.
int findRank(int x, vector<int> &BIT)
{
    return sum(x, BIT);
}
 
// Driver code
int main()
{
    vector<int> BIT(55);
    insertElement(20, BIT);
    insertElement(50, BIT);
    insertElement(30, BIT);
    insertElement(40, BIT);
 
    cout << "2nd Smallest element is "
     << findKthSmallest(2, BIT) << endl;
 
    cout << "Rank of 40 is "
         << findRank(40, BIT) << endl;
 
    deleteElement(40, BIT);
 
    cout << "Rank of 50 is "
         << findRank(50, BIT) << endl;
 
    return 0;
}
