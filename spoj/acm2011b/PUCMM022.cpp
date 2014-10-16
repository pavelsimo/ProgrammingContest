/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PUCMM022 C++ "Math, Geometry" */
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

typedef long long llong;

struct Circle {
   llong x, y, r; 
   Circle(llong  _x = 0, llong  _y = 0, llong  _r = 0) : 
      x(_x), y(_y), r(_r) {}
   bool operator<(const Circle &T) const {
      if(T.r != r) return r > T.r;
      if(T.x != x) return x < T.x;
      return y < T.r;
   }
};

Circle a[52];
const double PI = acos(-1.0);
double eps = 1e-5;

llong  dist(Circle a, Circle b) {
   return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main(int argc, char *argv[]) {
   double res;
   int TC, n, white;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      for(int i = 0; i < n; ++i)
         scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].r);
      sort(a,a+n);
      res = 0;
      for(int i = 0; i < n; ++i) {
         white = 1;
         for(int j = i - 1; j >= 0; --j) {
            if(dist(a[i],a[j]) < a[j].r * a[j].r) 
               white^=1;
         }
         if(white) res+=PI*a[i].r*a[i].r;
         else res-=PI*a[i].r*a[i].r;
      }
      printf("%lf\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
