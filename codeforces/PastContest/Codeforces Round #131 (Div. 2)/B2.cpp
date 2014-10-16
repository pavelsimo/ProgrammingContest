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


const int INF = 100000002;
vector<int> X;
int n;

int P[100002];
/*
int go(int cur, int prev, int rem2, int rem3, int rem5) {
   if(cur == n) 
      return !rem2 && !rem3 && !rem5 ? 0: -INF;
   if(memo[cur][rem2][rem3][rem5] >= 0) return memo[cur][rem2][rem3][rem5];
   int res = 0;
   int t1 = go(cur + 1, prev, rem2, rem3, rem5);
   int t2 = go(cur + 1, cur,(rem2 * 10 + X[cur]) % 2, (rem3 * 10 + X[cur]) % 3, (rem5 * 10 + X[cur]) % 5) + 1;
   if(t1 > res) res = t1;
   if(t2 > res) res = t2;
   return memo[cur][rem2][rem3][rem5] = res;
}
*/
int DP[100002][2][3][5];

int main(int argc, char *argv[]) {
   int ai, r2, r3, r5;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> ai;
      X.push_back(ai);
   }
   sort(X.rbegin(), X.rend());
   DP[0][0][0][0] = 0;
   r2 = r3 = r5 = 0;
   for(int i = 0; i < sz(X); ++i) {
      DP[i][r2][r3][r5] = DP[i - 1][r2][r3][r5];
      r2 = (r2*10 + X[i]) % 2;
      r3 = (r3*10 + X[i]) % 3;
      r5 = (r5*10 + X[i]) % 5;
   }
   return 0;
}

