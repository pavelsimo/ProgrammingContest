/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  478  C++  "Geometry, Point Inside a Rectangle, Circle and Triangle" */
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

#define RECTANGLE 0
#define CIRCLE 1
#define TRIANGLE 2

const int MAXN = 12;
point p, p_top[MAXN], p_bottom[MAXN], p_left[MAXN];
int type[MAXN];

char buf[256];

bool pointInCircle(point p, point c, double r) {
   double dx = p.x - c.x;
   double dy = p.y - c.y;
   return dx*dx + dy*dy < r*r;
}

bool pointInTriangle(point p, point a, point b, point c) {
   bool b1 = ((p - a) ^ (b - a)) > 0;
   bool b2 = ((p - b) ^ (c - b)) > 0;
   bool b3 = ((p - c) ^ (a - c)) > 0;   
   return (b1 && b2 && b3) || (!b1 && !b2 && !b3);
}

bool pointInRectangle(point a, point b) {
   double maxx = max(a.x,b.x);
   double minx = min(a.x,b.x);
   double maxy = max(a.y,b.y);
   double miny = min(a.y,b.y);
   return p.x > minx && p.x < maxx && p.y > miny && p.y < maxy;
}

int main(int argc, char *argv[]) {
   int N;
   char ch;
   N = 0;
   while(gets(buf)) {
      if(buf[0]=='*') break;
      if(buf[0]=='r') {
         type[N] = RECTANGLE;
         sscanf(buf,"%c%lf%lf%lf%lf",&ch,&p_top[N].x,&p_top[N].y,&p_bottom[N].x,&p_bottom[N].y);
      } else if(buf[0]=='c') {
         type[N] = CIRCLE;
         sscanf(buf,"%c%lf%lf%lf",&ch,&p_top[N].x,&p_top[N].y,&p_bottom[N].x);
      } else if(buf[0]=='t') { 
         type[N] = TRIANGLE;
         sscanf(buf,"%c%lf%lf%lf%lf%lf%lf",&ch,&p_top[N].x,&p_top[N].y,&p_bottom[N].x,&p_bottom[N].y,&p_left[N].x,&p_left[N].y);
      }
      N++;
   }
   for(int k = 1; 2 == scanf("%lf%lf",&p.x,&p.y); ++k) {
      if(fabs(p.x - 9999.9) < EPS && fabs(p.y - 9999.9) < EPS) break;
      bool found = false;
      for(int i = 0; i < N; ++i) {
         if(type[i] == RECTANGLE) {
            if(pointInRectangle(p_top[i],p_bottom[i])) {
               printf("Point %d is contained in figure %d\n",k, i + 1);
               found = true;
            }            
         } else if(type[i] == CIRCLE) {            
            double radius = p_bottom[i].x;
            if(pointInCircle(p, p_top[i], radius)) {
               printf("Point %d is contained in figure %d\n",k, i + 1);
               found = true;  
            }
         } else if(type[i] == TRIANGLE) {
            if(pointInTriangle(p, p_top[i], p_bottom[i], p_left[i])) {
               printf("Point %d is contained in figure %d\n",k, i + 1);
               found = true;
            }
         }
      }
      if(!found) printf("Point %d is not contained in any figure\n",k);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

