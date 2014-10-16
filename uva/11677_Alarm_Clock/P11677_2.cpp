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
   int H1, M1, H2, M2, res, t1, t2;
   while(scanf("%d%d%d%d",&H1,&M1,&H2,&M2)==4) {
      if(H1==0 && M1==0 && H2==0 && M2==0) break;
      t1 = H1*60 + M1;
      t2 = H2*60 + M2;
      if(t2 < t1) t2+=1440;
      res = t2-t1;
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
