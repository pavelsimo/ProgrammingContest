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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const double EPS = 1e-12;

struct Point {
  double x, y; 
};

int cross(Point a, Point b, Point c) {
  double d = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
  if (d > EPS) return +1;
  else if (d < -EPS) return -1;
  return  0;
}

Point P[102], q;

int main(int argc, char *argv[]) { 
   int TC, n, m, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      for(int i = 0; i < n; ++i)
         scanf("%lf%lf",&P[i].x,&P[i].y);
      scanf("%d",&m);
      while(m-- > 0) {
         scanf("%lf%lf",&q.x,&q.y);
         res = 0;
         for(int i = 0; i < n; ++i) {
            if(cross(P[i], P[(i + 1) % n], q) < 0) 
               res++;
         }
         printf("%d\n",res);
      }
      printf("\n");
   }   
   return 0;
}

