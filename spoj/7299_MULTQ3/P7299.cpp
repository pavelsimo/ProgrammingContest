/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MULTQ3 C++ "Segment Tree, Data Structure" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

using namespace std;

int N;
const int MAXN = 200002;

class SegmentTree {
   
public:

   int N;

   struct Node {
      llong sum, delay;
      Node(): sum(0), delay(0) {}
   };
   
   vector<Node> tree;

   SegmentTree(int _N) {
      N = _N;
      tree = vector<Node>(4 * N);
   }
   
   llong query(int i, int j) {
      return _query(1, 0, N - 1, i, j);
   }
     
   llong _query(int node, int L, int R, int i, int j) {

      if (j < L || i > R) return 0;
      
      if(L >= i && R <= j) return tree[node].sum;
      
      int mid = (L + R) / 2;
         
      if(tree[node].delay != 0) {
         llong lenL = mid - L + 1;
         llong lenR = R - L + 1 - lenL;
         
         tree[2 * node].delay += tree[node].delay;
         tree[2 * node].sum   += lenL * tree[node].delay;
         
         tree[2 * node + 1].delay += tree[node].delay;
         tree[2 * node + 1].sum   += lenR * tree[node].delay;
         
         tree[node].delay = 0LL;
      }
      return _query(2*node, L, mid, i, j) + _query(2*node+1, mid + 1, R, i, j);
   }
   
   void update(int i, int j, llong val) {
      _update(1, i, j, val, 0, N - 1);
   }
   
   void _update(int node, int i, int j, llong val, int L, int R) {
      
      if(j < L || R < i)
         return;
         
      // |---|i---|L-----R|---j|---|
      if (i <= L && R <= j) {
         tree[node].delay += val;
         tree[node].sum   += val * (R-L+1);
         return;
      }
      
      int mid = (L + R) / 2;
      
      // Lazy propagation
      if(tree[node].delay != 0) {
         
         llong lenL = ((L+R)/2 - L + 1);
         llong lenR = (R - L + 1) - lenL;
         
         // propagate the sum in the left subtree
         tree[2 * node].delay += tree[node].delay;
         tree[2 * node].sum   += lenL * tree[node].delay;
         
         // propagate the sum in the right subtree
         tree[2 * node + 1].delay += tree[node].delay;
         tree[2 * node + 1].sum   += lenR * tree[node].delay;
         
         // clean the delay
         tree[node].delay = 0LL;
      }
      _update(2 * node, i, j, val, L, mid);
      _update(2 * node + 1, i, j, val, mid + 1, R);
      tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
   }
};

int main(int argc, char *argv[]) {
   int TC, opt, p, q, Q;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&N,&Q);
      SegmentTree st(N);
      while(Q-- > 0) {
         scanf("%d",&opt);
         scanf("%d%d",&p,&q);
         --p, --q;
         if(opt) {
            printf("%lld\n", st.query(p, q));
         } else {
            st.update(p, q, 1);
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
