/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ GSS1 C++ "Segment Tree, Data Structures" */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define DEBUG(x) cout << #x << ": " << x << endl
#define HIGHESTSETBIT(mask) ( sizeof(int)*8-1-__builtin_clz((mask)) )

using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
   int suffix, prefix, sum, ans;
   Node(int _suffix = -INF, int _prefix  = -INF, int _sum = -INF, int _ans = -INF) :
      suffix(_suffix), prefix(_prefix), sum(_sum), ans(_ans) { }
};

class RMQ_SegmentTree {
   
public:
   vector<int> A;
   vector<Node> tree;

   RMQ_SegmentTree(vector<int> &_A) : A(_A) {
      int N = A.size();
      int LOGN = floor(log(A.size()) / log(2)) + 1;
      tree = vector<Node>(2 * (1<<LOGN) + 1);
      build(1, 0, N-1);
   }
   
   Node make_node(int val) {
      Node res;
      res.sum = val;
      res.suffix = res.prefix = res.ans = max(-INF, val);
      return res;
   } 
   
   Node get_node_max(Node l, Node r) {
      Node res;
      res.sum = l.sum + r.sum;
      res.prefix = max(l.prefix, l.sum + r.prefix);
      res.suffix = max(r.suffix, l.suffix + r.sum);
      res.ans = max(l.suffix + r.prefix, max(l.ans, r.ans));
      return res;
   }

   void build(int node, int lo, int hi) {
      if(lo==hi) {
         tree[node] = make_node(A[lo]);
         return;
      }
      int mid = (lo+hi)/2;
      build(2*node, lo, mid);
      build(2*node + 1, mid + 1, hi);
      tree[node] = get_node_max(tree[2*node], tree[2*node+1]);
   }
   
   int query(int i, int j) {
      Node q = _query(1, 0, A.size() - 1, i, j);
      return q.ans;
   }
     
   Node _query( int node, int lo, int hi, int i, int j ) {
      if ( i == lo && hi == j )
         return tree[node] ;
      int mid = ( lo + hi ) / 2 ;
      if ( j <= mid )
         return _query ( node * 2 , lo, mid , i, j );
      if ( i > mid )
         return _query ( node * 2 + 1 , mid + 1 , hi, i, j ) ;
      return get_node_max (
         _query ( node * 2 , lo, mid , i, mid ) ,
         _query ( node * 2 + 1 , mid + 1 , hi, mid + 1, j )
      );
   }
 
};

int main() {
   vector<int> A;
   int N, Q, ai, lo, hi;
   scanf("%d",&N);
   for(int i = 0; i < N; ++i) {
      scanf("%d",&ai);
      A.push_back(ai);
   }
   RMQ_SegmentTree st(A);
   scanf("%d",&Q);
   while(Q-- > 0) {
      scanf("%d%d",&lo,&hi);
      --lo, --hi;
      printf("%d\n",st.query(lo,hi));
   }
   return 0;
}
