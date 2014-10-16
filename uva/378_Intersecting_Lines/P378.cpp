/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  378  C++  "Geometry, Line Intersection" */
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

const double EPS = 1e-9;
struct point_i  { int x, y;       };
struct point    { double x, y;    };
struct line     { double a, b, c; };

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

bool is_parallel(line l1, line l2) {
   return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool is_same_line(line l1, line l2) {
   return is_parallel(l1,l2) && fabs(l1.c - l2.c) < EPS;
}

bool intersect(line l1, line l2, point *p) {
   if(is_parallel(l1,l2) || is_same_line(l1,l2)) 
      return false;
   p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
   if(fabs(l1.b) > EPS) 
      p->y = -(l1.a * p->x + l1.c) / l1.b;
   else
      p->y = -(l2.a * p->x + l2.c) / l2.b;
   return true;
}

int main(int argc, char *argv[]) {
   int TC;
   line l1, l2;
   point_i p1, p2, p3, p4;
   point p5;
   scanf("%d",&TC);
   puts("INTERSECTING LINES OUTPUT");
   while(TC-- > 0) {
      scanf("%d%d%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
      points_to_line(p1,p2,&l1);
      points_to_line(p3,p4,&l2);
      if(is_same_line(l1,l2)) puts("LINE");
      else if(is_parallel(l1,l2)) puts("NONE");
      else intersect(l1,l2,&p5), printf("POINT %.2lf %.2lf\n",p5.x,p5.y);
   }
   puts("END OF OUTPUT");
   return 0;
}
/* @END_OF_SOURCE_CODE */
