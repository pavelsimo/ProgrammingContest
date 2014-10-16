/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  118  C++  "Graph Theory" */
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

typedef pair<int,int> PII;

char s[128];
const string dir = "NESW";
int seen[55][55];
int dx[] = {+0,+1,+0,-1};
int dy[] = {+1,+0,-1,+0};

int main(int argc, char *argv[]) {
   memset(seen,false,sizeof(seen));
   int N, M, k, x, y;
   char ch;
   gets(s);
   sscanf(s,"%d%d",&N,&M);
   while(gets(s)) {
      if(sscanf(s,"%d %d %c",&x, &y, &ch) != 3) break;
      gets(s);
      k = strlen(s);
      int d = dir.find(ch);
      bool lost = false;
      for(int i = 0; i < k; ++i) {
         if(s[i]=='R') {
            d = (d + 1) % 4;
         } else if(s[i]=='L') {
            d = (4 + d - 1) % 4;
         } else {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx <= N && ny >= 0 && ny <= M) {
               x = nx;
               y = ny;
            } else {
               if(!seen[x][y]) {
                  lost = true;
                  seen[x][y] = true;
                  break;
               }
            }
         }
      }
      printf("%d %d %c",x,y,dir[d]);
      if(lost) printf(" LOST\n");
      else putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
