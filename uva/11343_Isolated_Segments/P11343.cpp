/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11343  C++  "Geometry, Line Segments Intersection" */
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

const double EPS = 1e-6;

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
};

double direction(point p1, point p2, point p3) {
   return (p3 - p1) ^ (p2 - p1);
}

bool on_segment(point p1, point p2, point p3) {
   double minx = min(p1.x,p2.x);
   double maxx = max(p1.x,p2.x);
   double miny = min(p1.y,p2.y);
   double maxy = max(p1.y,p2.y);
   return p3.x >= minx - EPS && p3.x <= maxx + EPS && p3.y >= miny - EPS && p3.y <= maxy + EPS;
}

bool segments_intersect(point p1, point p2, point p3, point p4) {  
   double d1 = direction(p3,p4,p1);
   double d2 = direction(p3,p4,p2);
   double d3 = direction(p1,p2,p3);
   double d4 = direction(p1,p2,p4);
   if(d1 * d2 < -EPS && d3 * d4 < -EPS) return true;
   else if(fabs(d1) < EPS && on_segment(p3,p4,p1)) return true;
   else if(fabs(d2) < EPS && on_segment(p3,p4,p2)) return true;
   else if(fabs(d3) < EPS && on_segment(p1,p2,p3)) return true;
   else if(fabs(d4) < EPS && on_segment(p1,p2,p4)) return true;
   return false;
}

const int MAXN = 102;
point src[MAXN], dst[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);   
      for(int i = 0; i < N; ++i)
         scanf("%lf%lf%lf%lf",&src[i].x,&src[i].y,&dst[i].x,&dst[i].y);
      res = 0;
      for(int i = 0; i < N; ++i) {
         int j;
         for(j = 0; j < N; ++j) {
            if(i == j) continue;
            if(segments_intersect(src[i],dst[i],src[j],dst[j])) break;
         }
         if(j == N) res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

