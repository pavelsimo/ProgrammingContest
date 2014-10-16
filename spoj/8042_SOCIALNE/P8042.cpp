/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SOCIALNE C++ "Graph Theory" */
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

char A[60][60];

int main(int argc, char *argv[]) {
   int TC, N, res, pfriends;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%s",A[0]);
      N = strlen(A[0]);
      for(int i = 1; i < N; ++i)
         scanf("%s",A[i]);
      res = pfriends = 0;
      for(int i = 0; i < N; ++i) {
         int cnt = 0;
         for(int j = 0; j < N; ++j) {
            if(i==j) continue;
            if(A[i][j]=='N') {
               for(int k = 0; k < N; ++k) {
                  if(k==i || k==j) continue;
                  if(A[i][k]=='Y' && A[k][j]=='Y') {
                     cnt++;
                     break;
                  }
               }
            }                        
         }
         if(cnt > pfriends) {
            pfriends = cnt;
            res = i;
         }
      }
      printf("%d %d\n",res,pfriends);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
