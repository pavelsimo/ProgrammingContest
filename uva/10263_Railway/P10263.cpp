/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10263  C++  "Geometry, Vectors, Line Point Distance" */
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

const double INF = 0x3f3f3f3f, EPS = 1e-7;

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

double linePointDist(point A, point B, point C, point *ans, bool isSegment){
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

int main(int argc, char *argv[]) {
   int n;
   double best;
   point a, b, c, t, ans;
   while(2 == scanf("%lf%lf",&c.x, &c.y)) {
      scanf("%d",&n);
      scanf("%lf%lf",&a.x,&a.y);
      best = INF;
      for(int i = 0; i < n; ++i) {
         scanf("%lf%lf",&b.x,&b.y);   
         double dist = linePointDist(a,b,c,&t,true);
         if(dist < best) {
            best = dist;
            ans = t;
         } 
         a = b;
      }
      printf("%.4lf\n%.4lf\n",ans.x,ans.y);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
