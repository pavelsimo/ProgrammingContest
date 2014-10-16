/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CISTFILL C++ "Binary Search" */
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
int N;
const int MAXN = 50010;
int B[MAXN], H[MAXN], W[MAXN], D[MAXN], V;

double f(double d) {
   double res = 0.0;
   for(int i = 0; i < N; ++i) {
     if(d >= B[i]+H[i])
        res+=H[i]*W[i]*D[i];
     else if(d >= B[i] && d < B[i]+H[i])
        res+=(d-B[i])*W[i]*D[i];
   }
   return res;
}

int main(int argc, char *argv[]) {
   int TC;
   double lo, hi;
   llong sum;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      lo = 0.0;
      hi = 0.0;
      sum = 0;
      for(int i = 0; i < N; ++i) {
         scanf("%d%d%d%d",B+i,H+i,W+i,D+i);
         sum+=H[i]*W[i]*D[i];
         hi = max(hi,double(B[i]+H[i]));
      }
      scanf("%d",&V);
      if( V <= sum ) {
         for(int i = 0; i < 100; ++i) {
            double mid  = lo + (hi-lo)/2.0;
            if(f(mid) < V) 
               lo = mid;
            else
               hi = mid;
         }
         printf("%.2lf\n",lo);         
      } else {
         puts("OVERFLOW");
      }
      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
