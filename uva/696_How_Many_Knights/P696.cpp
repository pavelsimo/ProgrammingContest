/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  696  C++  "Ad Hoc, Chess" */
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

int main(int argc, char *argv[]) {
   int N, M, res;
   while(scanf("%d%d",&N,&M)==2) {
      if(N==0 && M==0) break;
      if(N==1 || M==1) {
         res = max(N,M);
      } else if(N==2 || M==2) {
         //int F = max(M,N);
         //res = (F/4)*4 + min(4,(F%4)*2);
         bool flag = true;
         res = 0;
         for(int i = 0; i <= N*M; i+=4) {
            if(flag) {
               if(i + 4 <= N*M) res+=4;
               else if(i + 2 <= N*M) res+=2;
            }
            flag=!flag;
         }
      } else {
         if(N%2==0) {
            int k = N/2;
            res = k * M;
         } else {
            int k1 = (N+1)/2;
            int k2 = N/2;
            if(M%2==0) {
               int h1 = M/2;
               res = k1*h1 + k2*h1;
            } else {
               int h1 = (M+1)/2;
               int h2 = M/2;
               res = k1*h1 + k2*h2;
            }
         }         
      }
      printf("%d knights may be placed on a %d row %d column board.\n",res,N,M);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
