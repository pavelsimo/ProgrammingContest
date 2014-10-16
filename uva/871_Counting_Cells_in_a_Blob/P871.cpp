/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  871  C++  "Graph Theory, DFS, flood fill" */
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

int N, cnt;
char B[30][30], buf[30];
int dr[] = {+1,+0,-1,+0,+1,+1,-1,-1};
int dc[] = {+0,+1,+0,-1,+1,-1,+1,-1};

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= N || B[i][j]!='1') return;
   cnt++;
   B[i][j]='0';
   for(int dir = 0; dir < 8; ++dir)
      dfs(i + dr[dir], j + dc[dir]);
}

int main(int argc, char *argv[]) {
   int TC, res;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      gets(buf);  
      gets(B[0]);
      N = strlen(B[0]);
      for(int i = 1; i < N; ++i)
         gets(B[i]);
      res = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(B[i][j]=='1') {
               cnt = 0;
               dfs(i,j);
               res = max(res,cnt);
            }
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
