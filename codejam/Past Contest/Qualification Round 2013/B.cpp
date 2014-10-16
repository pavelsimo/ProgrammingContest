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

const int MAXN = 202;
int a[MAXN][MAXN], N, M;

bool solve() {
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {
         int ii, jj;
         // vertical
         for(ii = 0; ii < N; ++ii)
            if(a[ii][j] > a[i][j]) break;
         // horizontal
         for(jj = 0; jj < M; ++jj)
            if(a[i][jj] > a[i][j]) break;         
         if(ii >= N || jj >= M) continue;
         return false;
      }
   }
   return true;
}

int main(int argc, char *argv[]) { 
   int TC;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&M);
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            scanf("%d",&a[i][j]);
         }
      }
      printf("Case #%d: %s\n", tc, solve() ? "YES": "NO");
   }
   return 0;
}
