/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  476  C++  "Geometry, Point Inside a Rectangle" */
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

const int MAXN = 12;
point p, top[MAXN], bottom[MAXN];
char buf[256];

int main(int argc, char *argv[]) {
   int N;
   char ch;
   N = 0;
   while(gets(buf)) {
      if(buf[0]=='*') break;
      sscanf(buf,"%c%lf%lf%lf%lf",&ch,&top[N].x,&top[N].y,&bottom[N].x,&bottom[N].y);
      N++;
   }
   for(int k = 1; 2 == scanf("%lf%lf",&p.x,&p.y); ++k) {
      if(fabs(p.x - 9999.9) < EPS && fabs(p.y - 9999.9) < EPS) break;
      bool found = false;
      for(int i = 0; i < N; ++i) {
         double maxx = max(top[i].x,bottom[i].x);
         double minx = min(top[i].x,bottom[i].x);
         double maxy = max(top[i].y,bottom[i].y);
         double miny = min(top[i].y,bottom[i].y);
         if(p.x > minx && p.x < maxx && p.y > miny && p.y < maxy) {
            printf("Point %d is contained in figure %d\n",k, i + 1);
            found = true;
         }
      }
      if(!found) printf("Point %d is not contained in any figure\n",k);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

