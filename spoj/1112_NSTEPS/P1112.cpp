/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ NSTEPS C++ "Ad Hoc, Simple Math" */
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

typedef pair<int,int> ii;
map<ii,int> m_pts;
int dx[] = {+1,+1,+1,-1};
int dy[] = {+1,-1,+1,+1};

int main(int argc, char *argv[]) {
   int nx = 0, ny = 0, dir = 0;
   m_pts[ii(nx,ny)] = 0;
   for(int i = 1; i <= 10010; ++i) {
      nx += dx[dir];
      ny += dy[dir];
      m_pts[ii(nx,ny)] = i;
      dir++;
      dir%=4;
   }
   int TC, x, y;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&x,&y);
      if(m_pts.count(ii(x,y))!=0) 
         printf("%d\n",m_pts[ii(x,y)]);
      else
         puts("No Number");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

