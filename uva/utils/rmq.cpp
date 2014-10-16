#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

/*
 * Log Intervals
 * <O(N log N), O(1)> RMQ
 * M[i][j] is the index of the minimum value in the sub array
 *  starting at i having length 2^j
 */

#define HIGHESTSETBIT(mask) ( sizeof(int)*8-1-__builtin_clz((mask)) )

class RMQ {
   VVI M;
public:
   VI A;
   RMQ(int _N = 0) : A(_N) {}

   void preprocess() {
      int N = A.size();
      if (N == 0) return;

      int LOGN = HIGHESTSETBIT(N);
      M = VVI(N, VI(LOGN+1));

      // initialize M for the intervals with length 1
      for (int i = 0; i < N; i++)
         M[i][0] = i;

      //compute values from smaller to bigger intervals
      for (int j = 1; (1 << j) <= N; j++) {
         for (int i = 0; i + (1 << j) - 1 < N; i++) {
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
               M[i][j] = M[i][j - 1];
            else
               M[i][j] = M[i + (1 << (j - 1))][j - 1];
         }
      }
   }

   int query(int i, int j) {
   // int k = floor(log(j-i+1)/log(2));
      int k = HIGHESTSETBIT(j-i+1);
      if (A[ M[i][k] ] <= A[ M[j-(1<<k)+1][k] ])
         return M[i][k];
      else
         return M[j-(1<<k)+1][k];
   }
};


/*
 * Segment Tree
 * <O(N), O(log N)> RMQ
 * M[i] holds the minimum value position in the interval assigned to node i
 *   i is between 1 .. 2 * 2^( [lg(N)]+1 )
 */
class RMQ_SegmentTree {
   VI M;

   void _preprocess(int node, int L, int R) {
      if (L == R) {
         M[node] = L;
         return;
      }

    //compute the values in the left and right subtrees
      _preprocess(2 * node, L, (L + R) / 2);
      _preprocess(2 * node + 1, (L + R) / 2 + 1, R);

      const int& pL = M[2 * node];
      const int& pR = M[2 * node + 1];

    //search for the minimum value in the first and second half of the interval
      M[node] = A[pL] <= A[pR] ? pL : pR;
   } 

   int _query(int i, int j, int node, int L, int R) {
    //if the current interval doesn't intersect the query interval return -1
      if (i > R || j < L)
         return -1;
      
    //if the current interval is included in the query interval return M[node]
      if (i <= L && R <= j)
         return M[node];
      
    //compute the minimum position in the left and right part of the interval
      int pL = _query(i, j, 2 * node, L, (L + R) / 2);
      int pR = _query(i, j, 2 * node + 1, (L + R) / 2 + 1, R);
      
    //return the position where the overall minimum is
      if (pL < 0) return pR;
      if (pR < 0) return pL;
      return A[pL] <= A[pR] ? pL : pR;
   }

public:
   VI A;
   RMQ_SegmentTree(int _N) : A(_N) {}
   
   void preprocess() {
      int N = A.size();
      int MAXIND = 2 * ( 1 << int( floor(log(N)/log(2))+1 ) ) + 1;
      M = VI(MAXIND, -1);
      _preprocess(1, 0, N-1);
   }

   int query(int i, int j) {
      return _query(i, j, 1, 0, int(A.size())-1);
   }

};

int main() {
   return 0;
}
