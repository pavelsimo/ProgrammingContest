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


const int INF = 1000000;
int n, m, k;
char buf[128], board[128][128];
int memo[102][102][14], next[102][102][14];

int go(int i, int j, int mod) {
   if(i < 0) return mod == 0 ? 0: -INF;
   if(j < 0 || j >= m) return -INF;
   if(memo[i][j][mod] != -1) return memo[i][j][mod];   
   int res = -INF;
   int n_mod = mod + board[i][j] - '0';
   while(n_mod >= k + 1) n_mod -= (k+1);
   int lu = go(i - 1, j - 1, n_mod) + board[i][j] - '0';
   int ru = go(i - 1, j + 1, n_mod) + board[i][j] - '0';
   if(lu > res) {
      res = lu;
      next[i][j][mod] = j - 1;
   }
   if(ru > res) {
      res = ru;
      next[i][j][mod] = j + 1;
   }
   return memo[i][j][mod] = res;
}

int main(int argc, char *argv[]) {
   int res, j, best;
   gets(buf);
   sscanf(buf,"%d%d%d",&n,&m,&k);
   for(int i = 0; i < n; ++i) 
      gets(board[i]);
   memset(memo, -1, sizeof(memo));
   best = 0; res = -1;
   for(j = 0; j < m; ++j) {
      int x = go(n - 1, j, 0);
      if(x > res) {
         best = j;
         res = x;
      } 
   }
   if(res >= 0) {
      printf("%d\n%d\n",res,best + 1);
      j = best;
      for(int i = n - 1, mod = 0; i > 0; --i) {
         int nj = next[i][j][mod];
         if(nj > j) printf("R");
         else printf("L");
         mod = (mod + board[i][j] - '0') % (k + 1);
         j = nj;
      }
      printf("\n");
   } else {
      printf("-1\n");
   }
   return 0;
}

