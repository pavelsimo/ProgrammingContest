/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10310  C++  "Geometry, Euclidean Distance" */
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

int main(int argc, char *argv[]) {  
   int N;
   point p, p_gopher, p_dog, ans;
   double d_gopher, d_dog;
   while(5 == scanf("%d%lf%lf%lf%lf",&N,&p_gopher.x,&p_gopher.y,&p_dog.x,&p_dog.y)) {
      bool found = false;
      for(int i = 0; i < N; ++i) {
         scanf("%lf%lf",&p.x,&p.y);
         if(!found) {
            d_gopher = dist(p_gopher,p) * 2.0;
            d_dog = dist(p_dog,p);
            if(d_gopher < d_dog + EPS) {
               ans = p;
               found = true;
               printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",p.x,p.y);
            }
         }
      }
      if(!found) puts("The gopher cannot escape.");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
