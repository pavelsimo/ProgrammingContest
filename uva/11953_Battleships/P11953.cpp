/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11953  C++  "Graph Theory, DFS" */
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

char B[110][110];
int N, ship_part;

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= N || B[i][j]=='.') return;
   if(B[i][j]=='x') ship_part++;
   B[i][j] = '.';
   dfs(i + 1, j);
   dfs(i, j + 1);
   dfs(i - 1, j);
   dfs(i, j - 1);
}

int main(int argc, char *argv[]) {
   int TC, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%s",B[i]);
      res = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(B[i][j]!='.') {
               ship_part = 0;
               dfs(i,j);
               if(ship_part > 0) res++;
            }
         }
      }
      printf("Case %d: %d\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
