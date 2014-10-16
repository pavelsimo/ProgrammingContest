/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  270  C++  "Geometry, Slopes" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

struct point { 
   int x, y;
   point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
   // dot product
   int operator*(point T) const { 
      return x * T.x + y * T.y;  
   }
   point operator-(point T) const {
      return point(x - T.x, y - T.y);
   }
   // cross product
   int operator^(point T) const {
      return x * T.y - T.x * y;
   }
   bool operator<(const point &T) const {
      if(x != T.x) 
         return x < T.x;
      return y < T.y;
   }
   bool operator==(const point &T) const {
      return x == T.x && y == T.y;
   }
   bool operator!=(const point &T) const {
      return x != T.x || y != T.y;
   }
};

char buf[256];
const int MAXN = 702;
point P[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, res;
   gets(buf);
   sscanf(buf,"%d",&TC);
   gets(buf);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      N = 0;
      while(gets(buf)) {
         if(!strlen(buf)) break;
         sscanf(buf,"%d%d",&P[N].x,&P[N].y);
         ++N;
      }
      sort(P, P + N);
      res = 1;
      for(int i = 0; i < N; ++i) {
         point a = P[i];
         for(int j = i + 1; j < N; ++j) {
            point b = P[j];
            int cnt = 2;
            for(int k = j + 1; k < N; ++k) {
               point c = P[k];
               if((c.y - b.y) * (b.x - a.x) == (b.y - a.y) * (c.x - b.x)) {
                  cnt++;
                  b = P[k];
               }
            }
            res = max(res,cnt);
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

