/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10550  C++  "Ad Hoc, Math, Geometry, clockwise, counter-clockwise" */
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

int dabs(int n) {
   return n < 0 ? 360 + n: n;
}

int todegree(int n) {
   return 360*n/40;
}

/*
   clockwise         - angle (-) : angle_dist = src - dst
   counter-clockwise - angle (+) : angle_dist = dst - src
*/
int main(int argc, char *argv[]) {
   int S, X1, X2, X3, res;
   while(4==scanf("%d%d%d%d",&S,&X1,&X2,&X3)) {
      if(!S && !X1 && !X2 && !X3) break;
      res = 3*360;
      res+=dabs(todegree(S) - todegree(X1));  // clockwise
      res+=dabs(todegree(X2) - todegree(X1)); // counter-clockwise
      res+=dabs(todegree(X2) - todegree(X3)); // clockwise
      printf("%d\n",res);      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
