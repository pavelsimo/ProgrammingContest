/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ GNY07B C++ "Ad Hoc" */
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
   int TC;
   double x, res;
   string buf, unit, r_unit;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin,buf);
      istringstream in(buf);
      in >> x >> unit;
      res=0.0;
      if(unit=="kg") {
         r_unit="lb";
         res=x*2.2046;
      } else if(unit=="lb") {
         r_unit="kg";
         res=x*0.4536;
      } else if(unit=="g") {
         r_unit="l";
         res=x*3.7854;
      } else if(unit=="l") {
         r_unit="g";
         res=x*0.2642;
      }
      printf("%d %.4lf %s\n",tc, res, r_unit.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

