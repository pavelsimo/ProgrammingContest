/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11677  C++  "Ad Hoc" */
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
   int H1, M1, H2, M2, res;
   while(scanf("%d%d%d%d",&H1,&M1,&H2,&M2)==4) {
      if(H1==0 && M1==0 && H2==0 && M2==0) break;
      res = 0;
      while(H1 != H2 || M1 != M2) {
         res++;
         M1++;
         if(M1 >= 60) {
            H1++;
            M1 = 0;
         }
         if(H1 >= 24)
            H1 = 0;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
