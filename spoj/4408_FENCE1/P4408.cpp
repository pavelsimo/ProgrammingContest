/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FENCE1 C++ "Ad Hoc, Math, Geometry, Circle" */
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

const long double PI = atan(1.0)*4;

int main(int argc, char *argv[]) {
   int L;
   while(scanf("%d",&L)==1) {
      if(L==0) break;
      double r = L/PI;
      double area = PI*r*r/2.0;
      printf("%.2lf\n",area);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
