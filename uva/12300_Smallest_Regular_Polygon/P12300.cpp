/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12300  C++  "Geometry, Regular Polygons" */
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
};

double dist(point p1, point p2) {
   double dx = p1.x - p2.x;
   double dy = p1.y - p2.y;
   return sqrt(dx*dx + dy*dy);
}

const double PI = acos(-1.0);

int main(int argc, char *argv[]) {
   double angle, angle2, a, s, h, d, area, t;
   point p1, p2;
   int xa, ya, xb, yb, n;
   while(5 == scanf("%d%d%d%d%d",&xa,&ya,&xb,&yb,&n)) {
      if(!xa && !ya && !xb && !yb && !n) break;
      p1.x = xa; p1.y = ya;
      p2.x = xb; p2.y = yb;
      d = dist(p1,p2);
      angle = (360.0 / n) / 2.0;
      if(n % 2 == 0) {         
         h = d / 2.0;
      } else {
         t = d / 2.0;
         angle2=(360.0 / n);
         angle2*=(n-1)/2.0;
         angle2/=2.0;
         h = t / (sin(angle2*PI/180.0));
      }
      a = cos(angle*PI/180) * h;
      s = 2.0 *(h * sin(angle*PI/180.0));
      area = (n*s*a)/2.0;
      printf("%.6lf\n",area);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

