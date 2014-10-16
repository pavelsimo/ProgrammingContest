/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12299  C++  "RMQ, Segment Trees" */
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

typedef vector<int> VI;

const int INF = 1000002;

class SegmentTree {
   
public:
   VI A, tree;

   SegmentTree(VI &_A) : A(_A) {
      int N = A.size();
      tree = VI(4 * N, 1);
      build(1, 0, N - 1);
   }

   void build(int node, int lo, int hi) {
      if(lo == hi) {
         tree[node] = A[lo];
         return;
      }
      
      int mid = (lo+hi)/2;

      build(2*node, lo, mid);
      build(2*node + 1, mid + 1, hi);

      tree[node] = min(tree[2*node], tree[2*node+1]);
   }
   
   int query(int i, int j) {
      return _query(1, 0, A.size() - 1, i, j);
   }
     
   int _query(int node, int lo, int hi, int i, int j) {
      
      if(hi < i || lo > j) 
         return INF;

      if(lo >= i && hi <= j) 
         return tree[node];
      
      int mid = (lo + hi) / 2;

      return min(_query(2*node, lo, mid, i, j), _query(2*node+1, mid + 1, hi, i, j));
   }
   
   void update(int ind, int val) {
      _update(1, ind, val, 0, A.size() - 1);
   }
   
   void _update(int node, int ind, int val, int lo, int hi) {
      
      if(ind < lo || ind > hi)
         return;
         
      if(lo == hi) {
         tree[node] = val;
         return;
      }
      
      int mid = (lo + hi) / 2;
      _update(2*node, ind, val, lo, mid);
      _update(2*node + 1, ind, val, mid + 1, hi);
      
      tree[node] = min(tree[2*node], tree[2*node+1]);
   }
};

vector<int> A;
char s[128];
int X[1002], Y[1002];

int main(int argc, char *argv[]) {
   int n, m, q, x, ind, len;
   char opt;
   scanf("%d%d",&n,&q);
   for(int i = 0; i < n; ++i) {
      scanf("%d",&x);
      A.push_back(x);
   }
   SegmentTree st(A);
   while(q-- > 0) {
      scanf("%s",s);
      opt = s[0];
      ind = strchr(s, '(') - s + 1;
      len = strlen(s);
      x = m = 0;
      for(int i = ind; i < len; ++i) {
         if(!isdigit(s[i])) {
            --x;
            X[m] = x, Y[m] = A[x];
            m++, x = 0;
         } else {
            x = x*10 + (s[i] - '0');
         }
      }  
      if(opt == 'q') {
         printf("%d\n",st.query(X[0], X[1]));
      } else {
         for(int i = 0; i < m - 1; ++i) {
            st.update(X[i], Y[i + 1]);
            A[X[i]] = Y[i + 1];
         }
         st.update(X[m - 1], Y[0]);
         A[X[m - 1]] = Y[0];
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
