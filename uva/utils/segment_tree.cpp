#include <cstdio>
#include <cmath>
#include <cassert>

#include <vector>
#include <algorithm>

using namespace std;

/*
 * Segment Tree
 * <O(N), O(log N)>
 * nodes[i] holds the segment tree value in the interval assigned to node i
 *   i is between 1 .. 2 * 2^( [lg(N)]+1 )
 */
class SegmentTree {
public:
   vector<int> A;
   SegmentTree(int _N) : A(vector<int>()) {}

   struct SegmentTreeNode {
   // int lb, ub;
      int prefix_sum, suffix_sum, best_sum, tot_sum;
      bool valid;
      SegmentTreeNode(
      // int _lb=-1, int _ub=-1,
         int _pref=0, int _suff=0, int _best=0, int _tot=0, bool _valid=false
      ) :
      // lb(_lb), ub(_ub),
         prefix_sum(_pref), suffix_sum(_suff),
         best_sum(_best), tot_sum(_tot), valid(_valid) {}
   };

   vector<SegmentTreeNode> tree;
private:

   void _preprocess(int node, int L, int R) {
      if (L == R) {
         tree[node] = SegmentTreeNode(/* L, R, */ A[L], A[L], A[L], A[L], true);
         return;
      }

      //compute the values in the left and right subtrees
      _preprocess(2*node, L, (L+R)/2);
      _preprocess(2*node+1, (L+R)/2+1, R);

      const SegmentTreeNode& pL = tree[2*node];
      const SegmentTreeNode& pR = tree[2*node+1];

      // assert(tree[2*node].max_freq >= 0);
      // assert(tree[2*node+1].max_freq >= 0);

      // merge the first and second half of the interval
      tree[node] = SegmentTreeNode(
                  //  L, R,
                      max(pL.prefix_sum, pL.tot_sum + pR.prefix_sum),
                      max(pR.suffix_sum, pR.tot_sum + pL.suffix_sum),
                      max(pL.suffix_sum + pR.prefix_sum,
                          max(pL.best_sum, pR.best_sum)),
                      pL.tot_sum + pR.tot_sum,
                      true
                   );
   }

   void _update(int idx, int val, int node, int L, int R) {
      if (idx < L || idx > R)
         return;
      
      if (L == R) {
         A[L] = val;
         tree[node] = SegmentTreeNode(/* L, R, */ A[L], A[L], A[L], A[L], true);
         return;
      }

      //compute the values in the left and right subtrees
      _update(idx, val, 2*node, L, (L+R)/2);
      _update(idx, val, 2*node+1, (L+R)/2+1, R);

      const SegmentTreeNode& pL = tree[2*node];
      const SegmentTreeNode& pR = tree[2*node+1];

      // assert(tree[2*node].max_freq >= 0);
      // assert(tree[2*node+1].max_freq >= 0);

      // merge the first and second half of the interval
      tree[node] = SegmentTreeNode(
                  //  L, R,
                      max(pL.prefix_sum, pL.tot_sum + pR.prefix_sum),
                      max(pR.suffix_sum, pR.tot_sum + pL.suffix_sum),
                      max(pL.suffix_sum + pR.prefix_sum,
                          max(pL.best_sum, pR.best_sum)),
                      pL.tot_sum + pR.tot_sum,
                      true
                   );
   }

   SegmentTreeNode _query(int i, int j, int node, int L, int R) {
      //if the current interval doesn't intersect the query interval return invalid interval
      if (i > R || j < L)
         return SegmentTreeNode();      

      //if the current interval is included in the query interval return M[node]
      if (i <= L && R <= j)
         return tree[node];

      //compute answer in the left and right part of the interval
      SegmentTreeNode pL = _query(i, j, 2*node, L, (L+R)/2);
      SegmentTreeNode pR = _query(i, j, 2*node+1, (L+R)/2+1, R);

      //if one of the interval is invalid, return the other
      if (!pL.valid) return pR;
      if (!pR.valid) return pL;

      //merge the answer
      return SegmentTreeNode(
            // L, R,
               max(pL.prefix_sum, pL.tot_sum + pR.prefix_sum),
               max(pR.suffix_sum, pR.tot_sum + pL.suffix_sum),
               max(pL.suffix_sum + pR.prefix_sum,
               max(pL.best_sum, pR.best_sum)),
                   pL.tot_sum + pR.tot_sum,
               true
            );
   }

public:
   void preprocess() {
      int N = A.size();
      int MAXIND = 2 * ( 1 << int( floor(log(N)/log(2))+1 ) ) + 1;
      tree = vector<SegmentTreeNode>(MAXIND);
      _preprocess(1, 0, N-1);
   }

   void update(int idx, int val) {
      _update(idx, val, 1, 0, int(A.size())-1);
   }

   SegmentTreeNode query(int i, int j) {
      return _query(i, j, 1, 0, int(A.size())-1);
   }

};

int main(int argc, char* argv[]) {
   int N;
   while (1 == scanf("%d", &N)) {
      SegmentTree st(N);
      for (int i = 0; i < N; ++i)
         scanf("%d", &st.A[i]);
      st.preprocess();
      int M;
      scanf("%d", &M);
      while (M-- > 0) {
         int op, x, y;
         scanf("%d %d %d", &op, &x, &y);
         --x;
         if (op == 0)
            st.update(x, y);
         else {
            --y;
            SegmentTree::SegmentTreeNode res = st.query(x, y);
            printf("%d\n", res.best_sum);
         }
      }
   }
   return 0;
}
