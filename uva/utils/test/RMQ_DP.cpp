#include<iostream>
#include<vector>

#define DEBUG(x) cout << #x << ": " << x << endl

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;

// RMQ <O(N^2), O(1)>
// http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor
class RMQ {
   VII DP;
public:
   VI A;
     
   RMQ(int _N = 0) : A(_N) {}
   
   RMQ(VI &_A) : A(_A) {
      preprocess();
   }
   
   void preprocess() {
      int N = A.size();
      DP = VII(N,VI(N));
      for(int i = 0; i < N; ++i)
         DP[i][i] = i;
      for(int i = 0; i < N; ++i) {
         for(int j = i + 1; j < N; ++j) {
              int best = DP[i][j-1];
              int cur = j;
              if(A[cur] < A[best])
                 DP[i][j] = cur;
              else
                 DP[i][j] = best;
         }
      }
   }
   
   int query(int i, int j) {
      return DP[i][j];
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
