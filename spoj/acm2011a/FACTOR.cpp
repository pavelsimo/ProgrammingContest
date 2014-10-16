/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FACTOR C++ "Ad Hoc" */
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

int mod(int n, int k) {
   return n<0?-(n%k):(n%k);
}

int main(int argc, char *argv[]) {
   int TC, A, B, K;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&A,&B,&K);
      int XA,XB;
      if(A < 0) XA = mod(A,K);
      else XA = K - mod(A,K);
      if(B < 0) XB = -(K - mod(B,K));
      else XB = -mod(B,K);
      if(mod(A,K)!= 0) A = min(A + XA, B);
      if(mod(B,K)!= 0) B = max(A, B + XB);
      if(A == B) {
         if(A%K == 0) puts("1");
         else puts("0");
      } else {
         printf("%d\n",(B-A)/K + 1);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
