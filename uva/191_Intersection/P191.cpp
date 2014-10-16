/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  191  C++  "Geometry, Line Segment Intersection" */
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

const double eps = 1e-7, INF = 0x3f3f3f3f;

struct point { 
   double x, y;
   point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
   // dot product
   int operator*(point T) const { 
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
   return p3.x >= minx - eps && p3.x <= maxx + eps && p3.y >= miny - eps && p3.y <= maxy + eps;
}

bool segments_intersect(point p1, point p2, point p3, point p4) {  
   double d1 = direction(p3,p4,p1);
   double d2 = direction(p3,p4,p2);
   double d3 = direction(p1,p2,p3);
   double d4 = direction(p1,p2,p4);
   if(d1 * d2 < -eps && d3 * d4 < -eps) return true;
   else if(fabs(d1) < eps && on_segment(p3,p4,p1)) return true;
   else if(fabs(d2) < eps && on_segment(p3,p4,p2)) return true;
   else if(fabs(d3) < eps && on_segment(p1,p2,p3)) return true;
   else if(fabs(d4) < eps && on_segment(p1,p2,p4)) return true;
   return false;
}

bool inside_rectangle(double xleft, double ytop, double xright, double ybottom, point p) {
   return p.x >= xleft - eps && p.x <= xright + eps && p.y >= ybottom - eps && p.y <= ytop + eps;
}

int main(int argc, char *argv[]) {
   int TC;
   double xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
      if(xright <= xleft + eps) swap(xleft,xright);
      if(ytop <= ybottom + eps) swap(ytop,ybottom);
      point p1(xstart,ystart), p2(xend,yend), p3(xleft,ytop), 
         p4(xright,ytop), p5(xright,ybottom), p6(xleft,ybottom);
      if((segments_intersect(p3,p4,p1,p2) || segments_intersect(p4,p5,p1,p2) 
         || segments_intersect(p5,p6,p1,p2) || segments_intersect(p6,p3,p1,p2)) 
         || (inside_rectangle(xleft, ytop, xright, ybottom, p1) && inside_rectangle(xleft, ytop, xright, ybottom, p2))) {
         puts("T");        
      } else {
         puts("F");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

