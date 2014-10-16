#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define DEBUG(x) cout << #x << ": " << x << endl
#define HIGHESTSETBIT(mask) ( sizeof(int)*8-1-__builtin_clz((mask)) )

using namespace std;

typedef long long llong;   


class SegmentTree {
   
public:

   struct Node {
      llong sum, delay;
      Node(): sum(0), delay(0) {}
   };
   
   vector<llong> A;
   vector<Node> tree;

   SegmentTree(vector<llong> &_A) : A(_A) {
      int N = A.size();
      tree = vector<Node>(4 * N);
      build(1, 0, N - 1);
   }

   void build(int node, int lo, int hi) {
      if(lo==hi) {
         tree[node].sum = A[lo];
         return;
      }
      int mid = (lo+hi)/2;
      build(2*node, lo, mid);
      build(2*node + 1, mid + 1, hi);
      tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
   }
   
   llong query(int i, int j) {
      return _query(1, 0, A.size() - 1, i, j);
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
   
   void update(int i, int j, int val) {
      _update(1, i, j, val, 0, A.size() - 1);
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
      if(tree[node].delay != 0) {
         
         llong lenL = ((L+R)/2 - L + 1);
         llong lenR = (R - L + 1) - lenL;
         
         // propagate the sum in the left subtree
         tree[2 * node].delay += tree[node].delay;
         tree[2 * node].sum   += lenL * tree[node].delay;
         
         // propagate the sum in the right subtree
         tree[2 * node + 1].delay += tree[node].delay;
         tree[2 * node + 1].sum   += lenR * tree[node].delay;
         
         // clean the delay in the current node
         tree[node].delay = 0LL;
      }
      _update(2 * node, i, j, val, L, mid);
      _update(2 * node + 1, i, j, val, mid + 1, R);
      tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
   }
};

void print_array(vector<llong> &A) {
   for(int i = 0; i < int(A.size()); ++i)
      printf("%2lld ", A[i]);
   printf("\n");   
}

int main() {
   vector<llong> A;
   A.push_back(-1); A.push_back(2); A.push_back(5); 
   A.push_back(-7); A.push_back(2); A.push_back(8); A.push_back(-2);
   SegmentTree st(A);

   for(int i = 0; i < int(A.size()); ++i)
      printf("%2d ", i);
   printf("\n");
   print_array(A);
   printf("\n\n");
   
   DEBUG(st.query(0, A.size()-1));
   st.update(0,A.size()-1, +2);
   DEBUG(st.query(0, A.size()-1));
   st.update(0,A.size()-1, -8);
   DEBUG(st.query(0, A.size()-1));
   
   return 0;
}
