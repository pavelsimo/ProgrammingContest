/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10918  C++  "DP, Tiling" */
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

int rec(int n, int m) {
   if(n==0 && m==0) return 1;
   if(n < 0 || m < 0) return 0;
   return rec(n - 1, m - 2) + rec(n - 2, m -1);
}

int main(int argc, char *argv[]) {
   DEBUG(rec(12,3));
   return 0;
}
/* @END_OF_SOURCE_CODE */
