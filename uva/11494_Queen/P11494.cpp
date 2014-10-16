/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11494  C++  "Ad Hoc, Chess" */
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
   int x1, y1, x2, y2;
   while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4) {
      if(x1==0 && y1==0 && x2==0 && y2==0) break;
      if(x1 == x2 && y1== y2) puts("0");
      else if( abs(x1-x2) == abs(y1-y2) || x1 == x2 || y1 == y2)  puts("1");
      else puts("2");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
