#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define DEBUG(x) cout << #x << ": " << x << endl
#define HIGHESTSETBIT(mask) ( sizeof(int)*8-1-__builtin_clz((mask)) )

using namespace std;
typedef vector<int> VI;

// RMQ(i,j)  <O(N), O(logN)>
// http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor
class RMQ_SegmentTree {
   
public:
   VI A, M;

   RMQ_SegmentTree(VI &_A) : A(_A) {
      int N = A.size();
      int LOGN = floor(log(A.size()) / log(2)) + 1;
      M = VI(2*(1<<LOGN) + 1, -1);
      initialize(1,0,N-1);
   }

   void initialize(int node, int lo, int hi) {
      if(lo==hi) {
         M[node] = lo;
         return;
      }
      // computes the value for the left and the right subtrees
      int mid = (lo+hi)/2;
      initialize(2*node, lo, mid);
      initialize(2*node+1, mid + 1, hi);
      
      // search for the minimum value in the left and right part of the interval
      if(A[M[2*node]] <= A[M[2*node+1]]) 
         M[node] = M[2*node];
      else
         M[node] = M[2*node+1];
   }
   
   int query(int i, int j) {
      return _query(1,0,A.size()-1,i,j);
   }
   
   int _query(int node, int lo, int hi, int i, int j) {
      int p1, p2;
      
      // the current interval does not intersect query interval 
      if(hi < i || lo > j) 
         return -1;
         
      // if the current interval is included in ther query interval
      if(lo >= i && hi <= j) 
         return M[node];
      
      // compute the minimum position in the left and right part of the interval
      p1 = _query(2*node, lo, (lo+hi)/2, i, j);
      p2 = _query(2*node+1, (lo+hi)/2 + 1, hi, i, j);
      
      // return the position where the overall minimum is
      if(p1<0)  M[node] = p2;
      else if(p2<0) M[node] = p1;
      else if(A[p1] <= A[p2]) M[node] = p1;
      else M[node] = p2;
      
      return M[node];
   }
};

int main() {
   vector<int> A;
   A.push_back(2);   
   A.push_back(9);
   A.push_back(3);
   A.push_back(1);
   A.push_back(6);
   A.push_back(7);
   A.push_back(8);
   A.push_back(9);
   A.push_back(1);
   A.push_back(7);
   RMQ_SegmentTree obj(A);
   DEBUG(obj.query(1,2));
   DEBUG(obj.query(1,5));
   return 0;
}
