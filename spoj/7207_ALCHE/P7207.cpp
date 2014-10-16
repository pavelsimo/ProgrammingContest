/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ALCHE C++ "Ad Hoc, Math, Proportions" */
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

const int I = 1000, W = 37;

int main(int argc, char *argv[]) {
   int iron, water;
   while(scanf("%d%d",&iron,&water)==2) {
      if(iron==-1 && water==-1) break;
      if(W*iron == I*water) puts("Y");
      else puts("N");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
