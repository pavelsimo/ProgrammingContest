/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ LITE C++ "Segment Tree, Data Structure" */
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
      llong sum, inverse;
      Node(): sum(0), inverse(0) {}
   };
   
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
      if(tree[node].inverse) {
         tree[2 * node].inverse     ^= 1;
         tree[2 * node + 1].inverse ^= 1;
         tree[2 * node].sum      = lenL  - tree[2 * node].sum;
         tree[2 * node + 1].sum  = lenR  - tree[2 * node + 1].sum;
         tree[node].inverse = 0;
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
         
      // |---|i---|L-----R|---j|---|
      if (i <= L && R <= j) {
         tree[node].inverse ^= 1;
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

int main(int argc, char *argv[]) {
   int opt, p, q, Q;
   while(scanf("%d%d",&N,&Q) == 2) {
      SegmentTree st(N);
      while(Q-- > 0) {
         scanf("%d%d%d",&opt,&p,&q);
         --p, --q;
         if(opt) {
            printf("%lld\n", st.query(p, q));
         } else {
            st.update(p, q);
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
