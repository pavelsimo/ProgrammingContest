/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12034  C++  "Simple Math" */
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

const int MOD = 10056;
const int MAXN = 1010;

int N;
int nCr[MAXN][MAXN];
int memo[MAXN];

void preproccess() {
   memset(nCr,0,sizeof(nCr));
   nCr[0][0] = 1;
   for(int i = 1; i < MAXN; ++i) {
      for(int j = 0; j <= i; ++j) {
            if(j - 1 >= 0)
               nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%MOD;
            else
               nCr[i][j] = 1;
      }
   }
}

int doit(int K) {
   if(K == 0) return 1;
   int res = 0;
   if(memo[K]>=0) 
      return memo[K];
   for(int i = 1; i <= K; ++i)
      res = (res + nCr[K][i] * doit(K-i))%MOD;
   return memo[K] = res;
}

int main(int argc, char *argv[]) {
   preproccess();   
   int TC, res;
   scanf("%d",&TC);
   memset(memo,-1,sizeof(memo));
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      res = doit(N);
      printf("Case %d: %d\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
