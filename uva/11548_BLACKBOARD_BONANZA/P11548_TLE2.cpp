/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11548  C++  "String, Substrings" */
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

const int MAXN = 72;

char dict[MAXN][MAXN + 2];
int ai, bi;
int N, M, memo[MAXN][MAXN][MAXN][MAXN];
string A, B;

int go(int i, int j) {
   if(i == N || j == M) return 0;
   int &res = memo[ai][bi][i][j];
   if(res != -1) return res;
   res = 0;
   if(A[i] == B[j]) {
      res = max(res, max(go(i + 1, j + 1) + 1, max(go(i + 1, j),go(i, j + 1))));
   } else {
      res = go(i + 1, j);
      res = go(i, j + 1);
   }
   return res;
}

int main(int argc, char *argv[]) { 
   int TC, n, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      memset(memo, -1, sizeof(memo));
      scanf("%d",&n);
      for(int i = 0; i < n; ++i)
         scanf("%s",dict[i]);
      res = 0;
      for(int i = 0; i < n - 1; ++i) {
         ai = i;
         A = dict[i];
         N = sz(A);
         for(int j = i + 1; j < n; ++j) {
            bi = j;
            B = dict[j];
            M = sz(B);
            res = max(res, go(0,0));
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
