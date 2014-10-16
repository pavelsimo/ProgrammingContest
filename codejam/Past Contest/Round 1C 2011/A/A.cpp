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

char buf[256];
char a[55][55];
int R, C;

void dfs(int r, int c) {
   if(r < 0 || r >= R || c < 0 || c >= C || a[r][c]!='#') return;
   if(r+1 < R && c+1 < C) {
      if(a[r][c]=='#' && a[r][c+1]=='#' && a[r+1][c]=='#' && a[r+1][c+1]=='#') {
         a[r][c]='/'; a[r][c+1]='\\';
         a[r+1][c]='\\'; a[r+1][c+1]='/';
      }
   }
   dfs(r+1,c);
   dfs(r,c+1);
}

int main(int argc, char *argv[]) {
   int TC;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      gets(buf);
      sscanf(buf,"%d%d",&R,&C);
      for(int i = 0; i < R; ++i) {
         gets(a[i]);
      }
      for(int i = 0; i < R; ++i) {
         for(int j = 0; j < C; ++j) {
            if(a[i][j]=='#')
               dfs(i,j);
         }
      }
      bool ok = true;
      for(int i = 0; i < R; ++i) {
         for(int j = 0; j < C; ++j) {
            if(a[i][j]=='#') {
               ok = false;
               break;
            }
         }
         if(!ok) break;
      }
      printf("Case #%d:\n",tc);
      if(ok) {
         for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j)
               printf("%c",a[i][j]);
            putchar('\n');
         }         
      } else {
         puts("Impossible");
      }
   }
   return 0;
}

