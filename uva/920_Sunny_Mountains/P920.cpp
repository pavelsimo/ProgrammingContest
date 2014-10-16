/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  920  C++  "Geometry, Line Segment Intersection" */
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

const double EPS = 1e-7, INF = 0x3f3f3f3f;

struct point { 
   double x, y;
   point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
   // dot product
   double operator*(point T) const { 
      return x * T.x + y * T.y;  
   }
   point operator-(point T) const {
      return point(x - T.x, y - T.y);
   }
   // cross product
   double operator^(point T) const {
      return x * T.y - T.x * y;
   }
   point operator+(point T) const {
      return point(x + T.x, y + T.y);
   }
   bool operator<(const point &T) const {
      if(fabs(x - T.x) < EPS) 
         return y < T.y;
      return x < T.x;
   }
};

double dist(point p1, point p2) {
   double dx = p1.x - p2.x;
   double dy = p1.y - p2.y;
   return sqrt(dx*dx + dy*dy);   
}

const int MAXN = 102;
point P[MAXN];

/* parametric line equation
   x = b.x + t * m.x
   y = b.y + t * m.y
   y = ymax
   ymax = b.y + t * m.y
   t = ymax - b.y / m.y
*/
int main(int argc, char *argv[]) {
   int TC, N;
   double res, ymax, t;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);   
      for(int i = 0; i < N; ++i)
         scanf("%lf%lf",&P[i].x,&P[i].y);
      sort(P, P + N);
      ymax = res = 0.0;
      for(int i = N - 1; i >= 1; --i) {
         if(P[i - 1].y > ymax - EPS) {
            point M = P[i-1] - P[i];
            t = (ymax - P[i].y) / M.y;
            res+=dist(point(P[i].x + t * M.x, ymax), P[i - 1]);
            ymax = P[i - 1].y;
         }
      }
      printf("%.2lf\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

