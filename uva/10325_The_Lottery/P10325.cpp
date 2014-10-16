/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10325  C++  "Math, Inclusion-Exclusion Principle" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

template<typename INT>
INT lcm(INT a, INT b) {
// a*b/gcd(a,b) overflows !!!
   return a / gcd(a,b) * b;
}

typedef long long llong;
typedef vector<llong> VL;
VL A;

#define BITCOUNT(x) __builtin_popcount(x)

int main(int argc, char *argv[]) {
   llong N, a;
   int M;
   while(2==scanf("%lld%d",&N,&M)) {
      A.clear();
      for(int i = 0; i < M; ++i) {
         scanf("%lld",&a);
         A.push_back(a);
      }
      sort(all(A));
      for(int i = 0; i < M; ++i) {
         if(!A[i]) continue;
         for(int j = i + 1; j < M; ++j) {
            if(!A[j]) continue;
            if(gcd(A[j],A[i]) == A[i]) 
               A[j] = 0;
         }
      }
      M = remove(A.begin(),A.end(),0) - A.begin();
      A.resize(M);
      int S = 1 << sz(A);
      llong sum = 0;
      for(int i = 1; i < S; ++i) {
         llong prod = 1;
         for(int j = 0; j < sz(A); ++j)
            if(i & (1<<j)) 
               prod = lcm(prod,A[j]);
         if(BITCOUNT(i) & 1) 
            sum+=(N/prod);
         else 
            sum-=(N/prod);
      }
      printf("%lld\n",N-sum);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
