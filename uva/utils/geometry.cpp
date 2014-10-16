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

const double EPS = 1e-9;

struct line { 
   double a, b, c; 
};

struct point_i  { 
   int x, y;
   point_i(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct point { 
   double x, y;
   point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
   double operator*(const point &T) const { 
      // dot product
      return x * T.x + y * T.y;  
   }
   point operator*(const double &T) const { 
      // scale
      return point(x * T, y * T);  
   }
   point operator-(const point &T) const {
      // substraction
      return point(x - T.x, y - T.y);
   }
   point operator+(const point &T) const {
      // translation
      return point(x + T.x, y + T.y);
   }
   double operator^(const point &T) const {
      // cross product
      return x * T.y - T.x * y;
   }
};

void points_to_line(point_i p1, point_i p2, line *l) {
   if(p1.x == p2.x) {
      l->a = 1.0; 
      l->b = 0.0;
      l->c = -p1.x;
   } else {
      l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
      l->b = 1.0;
      l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
   }
}

double dist(point p1, point p2) {
   return hypot(p1.x - p2.x, p1.y - p2.y);   
}

bool is_equal(point p1, point p2) {
   return fabs(p1.x - p2.x) < EPS && fabs(p1. y - p2.y) < EPS;
}

bool is_equal(point_i p1, point_i p2) {
   return p1.x == p2.x && p2.x == p2.y;
}

bool is_parallel(line l1, line l2) {
   return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool is_same_line(line l1, line l2) {
   return is_parallel(l1,l2) && fabs(l1.c - l2.c) < EPS;
}

bool line_intersect(line l1, line l2, point *p) {
   if(is_parallel(l1,l2) || is_same_line(l1,l2)) 
      return false;
   p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
   if(fabs(l1.b) > EPS) 
      p->y = -(l1.a * p->x + l1.c) / l1.b;
   else
      p->y = -(l2.a * p->x + l2.c) / l2.b;
   return true;
}

double line_point_dist(point A, point B, point C, point *ans, bool isSegment){
  double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
  if(isSegment){
      if((C-A)*(A-B) > EPS) {
         ans->x = A.x;
         ans->y = A.y;
         return sqrt((A-C)*(A-C));
      }
      if((C-B)*(B-A) > EPS) {
         ans->x = B.x;
         ans->y = B.y;
         return sqrt((B-C)*(B-C));
      }
  }
  double scale = ((C.x - A.x) * (B.x - A.x) + (C.y - A.y) * (B.y - A.y)) / 
      ((double)(B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
  ans->x = A.x + scale * (B.x - A.x);
  ans->y = A.y + scale * (B.y - A.y);
  return fabs(dist);
}

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

int main(int argc, char *argv[]) {
   point A(1,0);
   point B(2,0);
   point C(0,0);
   point ans;
   DEBUG(line_point_dist(A,B,C,&ans,true));
   printf("%.4lf\n%.4lf\n",ans.x,ans.y);
   return 0;
}
// END CUT HERE
