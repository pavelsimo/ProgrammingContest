/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11227  C++  "Geometry, Vectors, Collinear Points" */
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

struct point { 
   int x, y;
   point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
   bool operator<(const point &T) const {
      if(x != T.x)
         return x < T.x; 
      return y < T.y;
   }
};

bool is_equal(point p1, point p2) {
   return p1.x == p2.x && p1.y == p2.y;
}

int cross(point p, point q, point r) {
   return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

const double EPS = 1e-7;
const int MAXN = 102;
vector<point> P;
set<point> S;

int main(int argc, char *argv[]) {  
   point p;
   double x, y;   
   int TC, N, tc = 1;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      P.clear(); S.clear();
      for(int i = 0; i < N; ++i) {
         scanf("%lf%lf",&x,&y);
         S.insert(point(x * 100 + EPS, y * 100 + EPS));
      }
      foreach(it,S) P.push_back(*it);
      int res = 1;
      for(int i = 0; i < sz(P); ++i) {
         for(int j = i + 1; j < sz(P); ++j) {
            int cnt = 2;
            for(int k = j + 1; k < sz(P); ++k)
               if(cross(P[i],P[k],P[j]) == 0) cnt++;
            res = max(res,cnt);
         }         
      }
      if(sz(P) > 1) printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",tc,sz(P),res);
      else printf("Data set #%d contains a single gnu.\n",tc);
      tc++;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
