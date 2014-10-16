/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  184  C++  "Geometry, Vectors, Collinear Points" */
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
   //point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
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

const int MAXN = 310;
point P[MAXN];
point T[MAXN];
char buf[128];

int main(int argc, char *argv[]) {  
   int N;
   point p;
   while(2 == scanf("%d%d",&p.x, &p.y)) {
      if(!p.x && !p.y) break;
      N = 0;
      P[0].x = p.x;
      P[0].y = p.y;
      N++;
      vector<string> ans;
      vector<bool> seen;
      while(2 == scanf("%d%d",&P[N].x, &P[N].y)) {
         if(!P[N].x && !P[N].y) break;
         N++;
      }
      sort(P,P+N);
      for(int i = 0; i < N; ++i) {
         for(int j = i + 1; j < N; ++j) {
            int cnt = 0;
            for(int k = i; k <= j; ++k) {
               if(cross(P[i],P[j],P[k]) == 0) {
                  T[cnt] = P[k];
                  cnt++;
               }
            }
            if(cnt > 2) {
               string s = "";
               for(int k = 0; k < cnt; ++k) {
                  sprintf(buf,"(%4d,%4d)",T[k].x,T[k].y);
                  s += buf;
               }
               seen.push_back(true);
               ans.push_back(s);
            }            
         }
      }
      sort(all(ans));
      for(int i = 0; i < sz(ans); ++i) {
         for(int j = 0; j < sz(ans); ++j) {
            if(i == j) continue;
            if(ans[j].find(ans[i]) != string::npos) {
               seen[i] = false;
               break;
            }
         }
      }
      if(sz(ans) > 0) {
         puts("The following lines were found:");
         for(int i = 0; i < sz(ans); ++i) {
            if(seen[i])
               puts(ans[i].c_str());
         }
      } else {
         puts("No lines were found");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
