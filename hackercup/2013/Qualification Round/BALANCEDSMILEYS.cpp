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

typedef long long llong;

string S;
int N;
int memo[202][202];

int rec(int n, int cntOpen) {
   if(cntOpen < 0) return 0;
   if(n >= N) return (cntOpen == 0);
   if(memo[n][cntOpen] != -1) return memo[n][cntOpen];
   int res = 0;
   if(S[n] == '(') {
      res |= rec(n + 1, cntOpen + 1);
   } else if(S[n] == ')') {
      res |= rec(n + 1, cntOpen - 1);
   } else if(S[n] == ':' && n + 1 < N && (S[n+1] == '(' || S[n+1] == ')')) {
      res |= rec(n + 1, cntOpen);
      res |= rec(n + 2, cntOpen);
   } else {
      res |= rec(n + 1, cntOpen);
   }
   return memo[n][cntOpen] = res;
}

int main(int argc, char *argv[]) { 
   int TC;
   getline(cin, S);
   sscanf(S.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin, S);
      memset(memo, -1, sizeof(memo));
      N = sz(S);
      int res = rec(0, 0);
      printf("Case #%d: %s\n", tc, res ? "YES" : "NO");
   }
   return 0;
}
