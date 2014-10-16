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
int memo[100002][2][3][5];
int P[100002][2][3][5];

int go(int cur, int rem2, int rem3, int rem5, int prev) {
   if(cur == n) 
      return !rem2 && !rem3 && !rem5 ? 0: -INF;
   int &res = memo[cur][rem2][rem3][rem5];
   if(res >= 0) return res;
   int t1 = go(cur + 1, rem2, rem3, rem5, prev);
   int t2 = go(cur + 1, (rem2 * 10 + X[cur]) % 2, 
      (rem3 * 10 + X[cur]) % 3, (rem5 * 10 + X[cur]) % 5, cur) + 1;
   if(t1 > res) {
      res = t1;
      P[cur][rem2][rem3][rem5] = prev;
   }
   if(t2 > res) {
      res = t2;
      P[cur][rem2][rem3][rem5] = prev;
   }
   return res;
}


int main(int argc, char *argv[]) {
   int ai;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> ai;
      X.push_back(ai);
   }
   sort(X.rbegin(), X.rend());
   memset(memo, -1, sizeof(memo));
   memset(P, -1, sizeof(P));
   DEBUG(go(0, 0, 0, 0, 0));
   return 0;
}

