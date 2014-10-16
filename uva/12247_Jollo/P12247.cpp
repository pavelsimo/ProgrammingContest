/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12247  C++  "Ad Hoc" */
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

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
   int P1[3], P2[3];
   int A, B, C, X, Y;
   while( 5 == scanf("%d%d%d%d%d",&A, &B, &C, &X, &Y) ) {
      if(!A && !B && !C && !X && !Y) break;
      int res = INF;
      for(int Z = 1; Z <= 52; ++Z) {
         if(Z == A || Z == B || Z == C || Z == X || Z == Y) continue;
         P1[0] = A; P1[1] = B; P1[2] = C;
         P2[0] = X; P2[1] = Y; P2[2] = Z;
         sort(P1,P1+3);
         sort(P2,P2+3);
         bool ok = true;
         do {
            do {
               int cnt = 0;
               for(int i = 0; i < 3; ++i) {
                  if(P2[i] > P1[i])
                     cnt++;
               }
               if(cnt < 2) {
                  ok = false;
                  break;
               }       
            } while(next_permutation(P2,P2+3));
            if(!ok) break;
         } while(next_permutation(P1,P1+3));
         if(ok) 
            res = min(res,Z);
      }
      if(res == INF) puts("-1");
      else printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
