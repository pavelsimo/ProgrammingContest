/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  579  C++  "Ad Hoc, Math, Geometry, clock" */
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
   int H, M;
   double res;
   while(2==scanf("%d:%d",&H,&M)) {
      if(!H && !M) break;
      res = (30.0*H) + (M/2.0) - (6.0*M);
      if(res < 0) res = res + 360.0;
      if(res > 180) res = 360.0 - res;
      printf("%.3lf\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
