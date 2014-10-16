#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

using namespace std;

class SegmentTree {
   
public:
   struct Node {
      llong sum, inv;
      Node(): sum(0), inv(0) {}
   };
   
   int N;
   vector<Node> tree;

   SegmentTree(int _N) {
      N = _N;
      tree = vector<Node>(4 * N);
   }
   
   llong query(int i, int j) {
      return _query(1, 0, N - 1, i, j);
   }
   
   void propagate(int node, int L, int R) {
      llong lenL = (L+R)/2 - L + 1;
      llong lenR = R - L + 1 - lenL;
      if(tree[node].inv) {
         tree[2 * node].inv     ^= 1;
         tree[2 * node].sum      = lenL  - tree[2 * node].sum;
         
         tree[2 * node + 1].inv ^= 1;
         tree[2 * node + 1].sum  = lenR  - tree[2 * node + 1].sum;
         
         tree[node].inv = 0;
      }
   }
     
   llong _query(int node, int L, int R, int i, int j) {
      if (j < L || i > R) return 0;
      
      if(L >= i && R <= j) return tree[node].sum;
      
      int mid = (L + R) / 2;
      
      propagate(node, L, R);      

      return _query(2*node, L, mid, i, j) + _query(2*node+1, mid + 1, R, i, j);
   }
   
   void update(int i, int j) {
      _update(1, i, j, 0, N - 1);
   }
   
   void _update(int node, int i, int j, int L, int R) {
      
      if(j < L || R < i)
         return;

      if (i <= L && R <= j) {
         tree[node].inv ^= 1;
         tree[node].sum = (R-L+1) - tree[node].sum;
         return;
      }
      
      int mid = (L + R) / 2;
      
      propagate(node, L, R);
     
      _update(2 * node, i, j, L, mid);
      _update(2 * node + 1, i, j, mid + 1, R);
      
      tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
   }
};

int A[100002];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   int n, q, t, l, r, x;
   cin >> n;
   vector<SegmentTree> st;
   for(int i = 0; i < n; ++i)
      cin >> A[i];
   for(int j = 0; j <= 20; ++j) {
      st.push_back(SegmentTree(n));
      for(int i = 0; i < n; ++i)
         if(A[i] & (1 << j)) st[j].update(i,i);
   }
   cin >> q;
   while(q-- > 0) {
      cin >> t >> l >> r;
      --l; --r;
      if(t == 1) {
         llong sum = 0LL;
         for(int i = 0; i <= 20; ++i) {
            llong cnt = st[i].query(l, r);
            sum += cnt * (1LL << i);
         }
         cout << sum << endl;
      } else {
         cin >> x;
         for(int i = 0; x; ++i, x >>= 1) {
            if(x & 1) 
               st[i].update(l, r);  
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
