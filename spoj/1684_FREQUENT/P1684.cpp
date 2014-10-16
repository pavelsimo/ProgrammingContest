/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ HORRIBLE C++ "Binary Index Tree, Fenwick, BIT, Data Structure" */
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


int main(int argc, char *argv[]) {
   


   return 0;
}
/* @END_OF_SOURCE_CODE */
