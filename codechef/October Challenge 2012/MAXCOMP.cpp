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

struct Event {
  int s, e, c; 
};

bool cmp(const Event &a, const Event &b) {
   if(a.e != b.e) return a.e < b.e;
   return a.s < b.s;
}

int N;
llong memo[2002][52];

Event A[2002];

llong go(int n, int e) {
   if(n == N) return 0;
   if(memo[n][e] != -1) 
      return memo[n][e];
   llong res = 0;
   if(e > A[n].s) {
      res = max(res, go(n + 1, e));
   } else {
      res = max(res, max(go(n + 1, e), go(n + 1, A[n].e) + A[n].c));
   }
   return memo[n][e] = res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N;
      memset(memo, -1, sizeof(memo));
      for(int i = 0; i < N; ++i) {
         cin >> A[i].s >> A[i].e >> A[i].c;
         ++A[i].s, ++A[i].e;
      }
      sort(A, A + N, cmp);
      cout << go(0, 0) << endl;
   }
   return 0;
}

