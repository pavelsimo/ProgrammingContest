/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  477  C++  "Geometry, Point Inside a Rectangle and Circle" */
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

#define RECTANGLE 0
#define CIRCLE 1

const int MAXN = 12;
point p, top[MAXN], bottom[MAXN];
int type[MAXN];

char buf[256];

bool inside_circle(point p, point c, double r) {
   double dx = p.x - c.x;
   double dy = p.y - c.y;
   return dx*dx + dy*dy < r*r;
}

int main(int argc, char *argv[]) {
   int N;
   char ch;
   N = 0;
   while(gets(buf)) {
      if(buf[0]=='*') break;
      if(buf[0]=='r') {
         type[N] = RECTANGLE;
         sscanf(buf,"%c%lf%lf%lf%lf",&ch,&top[N].x,&top[N].y,&bottom[N].x,&bottom[N].y);
      } else if(buf[0]=='c') {
         type[N] = CIRCLE;
         sscanf(buf,"%c%lf%lf%lf",&ch,&top[N].x,&top[N].y,&bottom[N].x);
      }
      N++;
   }
   for(int k = 1; 2 == scanf("%lf%lf",&p.x,&p.y); ++k) {
      if(fabs(p.x - 9999.9) < EPS && fabs(p.y - 9999.9) < EPS) break;
      bool found = false;
      for(int i = 0; i < N; ++i) {
         if(type[i] == RECTANGLE) {
            double maxx = max(top[i].x,bottom[i].x);
            double minx = min(top[i].x,bottom[i].x);
            double maxy = max(top[i].y,bottom[i].y);
            double miny = min(top[i].y,bottom[i].y);
            if(p.x > minx && p.x < maxx && p.y > miny && p.y < maxy) {
               printf("Point %d is contained in figure %d\n",k, i + 1);
               found = true;
            }            
         } else if(type[i] == CIRCLE) {
            double radius = bottom[i].x;
            if(inside_circle(p, top[i], radius)) {
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

