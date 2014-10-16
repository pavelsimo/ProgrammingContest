#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

#define DEBUG(x) cout << #x << ": " << x << endl

using namespace std;
typedef vector<int> VI;

// RMQ(i,j)  <O(N), O(sqrt(N))>
// http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor
class RMQ {
   
public:
   VI A, M;

   RMQ(VI &_A) : A(_A) {
      preprocess();
   }

   void preprocess() {
      int N = A.size();
      int k = int(sqrt(N));
      for(int i = 0, j = 0; i < N; ++i) {
         if(i%k==0) {
            if(i > 0) j++;
            M.push_back(i);
         } else if(A[i] < A[M[j]]) {
            M[j] = i;
         }
      }
   }
     
   int query(const int L, const int H) {
      int N = A.size();
      int k = int(sqrt(N));
      int res = L;
      int lo = 0, hi = 0;
      for(int i = 0; i < int(M.size()); ++i) {
         hi = min(N-1,lo + k-1);
         if(lo > H) break;
         if(lo >= L && hi <= H) {
            if(A[M[i]] < A[res])
               res = M[i];
         } else {
            if(lo < L) {
               for(int j = L; j <= hi; ++j)
                  if(A[j] < A[res])
                     res = j;
            }
            if(H < hi) {
               for(int j = lo; j <= H; ++j)
                  if(A[j] < A[res])
                     res = j;      
            }
         }
         lo = hi + 1;
      }
      return res;
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
   RMQ obj(A);
   DEBUG(obj.query(1,2));
   DEBUG(obj.query(1,5));
   return 0;
}
