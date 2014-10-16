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

int N, K;
const int INF = 100000000;
int memo[500002][27];
int a[500002][27], b[500002][27];
char S[500020];

int go(int n, int prev) {
   if(n == N) return 0;
   if(memo[n][prev] != -1) 
      return memo[n][prev];
   int res = INF;
   int cur = S[n] - 'A' + 1;
   if(prev != cur) {            
      int t = go(n + 1, cur);
      if(t < res) {
         res = t;
         a[n][prev] = n + 1;
         b[n][prev] = cur;
      }
   }
   for(cur = 1; cur <= K; ++cur) {
      if(prev == cur) continue;
      int t = go(n + 1, cur) + 1;
      if(t < res) {
         res = t;
         a[n][prev] = n + 1;
         b[n][prev] = cur;
      }
   }
   return memo[n][prev] = res;
}



int main(int argc, char *argv[]) {
   memset(memo, -1, sizeof(memo));
   gets(S);
   sscanf(S,"%d%d",&N,&K);
   gets(S);
   printf("%d\n",go(0,0));
   int i, j, t1, t2;
   for(i = a[0][0], j = b[0][0]; true; ) {
      printf("%c",'A' + j - 1);
      if(i == N) break;
      t1 = a[i][j];
      t2 = b[i][j];
      i = t1; 
      j = t2;
   }
   printf("\n");
   return 0;
}

