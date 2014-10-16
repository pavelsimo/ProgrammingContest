/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ QUALITY C++ "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   int TA, TB, TC, AA, AB, AC, solved, penalty, time;
   for(int tc = 1; 6==scanf("%d%d%d%d%d%d",&TA, &TB, &TC, &AA, &AB, &AC) ; ++tc ) {
      solved = penalty = time = 0;
      if(TA>0 && AA>0) solved++, time+=TA, penalty+=(AA-1)*20*60;
      if(TB>0 && AB>0) solved++, time+=TB, penalty+=(AB-1)*20*60;
      if(TC>0 && AC>0) solved++, time+=TC, penalty+=(AC-1)*20*60;
      printf("team %d: %d, %d\n",tc,solved,time+penalty);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

