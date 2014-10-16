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

int k1, k2;
int memo[102][102][12][12];
const int MOD = 100000000;

int rec(int n1, int n2, int x1, int x2) {
   if(n1==0 && n2==0) 
      return 1;
   int res = 0;
   if(memo[n1][n2][x1][x2] >= 0) 
      return memo[n1][n2][x1][x2];
   if(n1 > 0 && x1 < k1) res+=rec(n1 - 1, n2, x1 + 1, 0);
   if(n2 > 0 && x2 < k2) res+=rec(n1, n2 - 1, 0, x2 + 1);   
   return memo[n1][n2][x1][x2] = res % MOD;   
}

int main(int argc, char *argv[]) {
   int n1, n2;
   memset(memo,-1,sizeof(memo));
   cin >> n1 >> n2 >> k1 >> k2;
   cout << rec(n1,n2,0,0) << endl;
   return 0;
}

