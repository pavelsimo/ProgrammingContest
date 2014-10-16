/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10104  C++  "Extended Euclid, Linear Diophantine, GCD" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int X, Y, D;
void extendedEuclid(int a, int b) {
   if(b == 0) {
      X = 1; Y = 0; D = a;
      return;
   }
   extendedEuclid(b, a % b);
   int x1 = Y;
   int y1 = X - (a/b) * Y;
   X = x1;
   Y = y1;   
}

int main(int argc, char *argv[]) {
   int C;
   while(1 == scanf("%d",&C)) {
      if(!C) break;
      extendedEuclid(9, 1);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

