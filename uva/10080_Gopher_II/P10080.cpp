/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10080  C++  "Graph Theory, Bipartite Matching" */
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

typedef pair<double,double> Point;
typedef vector<int> VI;
typedef vector<Point> VP;

const int MAXN = 102;
int N, M, S, V;
VP gophers, holes;
VI v_left, v_right;
VI edges[MAXN];
bool seen[MAXN];

bool dfs(int cur) {
   if(seen[cur])
      return false;
   seen[cur] = true;
   for(int i = 0; i < sz(edges[cur]); ++i) {
      int nxt = edges[cur][i];
      if(v_right[nxt] == -1 || dfs(v_right[nxt])) {
         v_left[cur] = nxt;
         v_right[nxt] = cur;
         return true;
      }
   }
   return false;
}

int match() {
   int res = 0;
   bool aug_path_found = false;
   while(true) {
      memset(seen,false,sizeof(seen));
      aug_path_found = false;
      for(int i = 0; i < N; ++i) {
         if(v_left[i] == -1 && dfs(i))
            aug_path_found = true;      
      }
      if(!aug_path_found) break;
   }
   for(int i = 0; i < N; ++i)
      if(v_left[i] == -1)
         res++;
   return res;
}

double dist(Point p1, Point p2) {
   double dx = p1.first - p2.first;
   double dy = p1.second - p2.second;
   return dx*dx + dy*dy;
}

int main(int argc, char *argv[]) {
   Point p;
   int hi;
   while(4 == scanf("%d%d%d%d",&N,&M,&S,&V)) {
      for(int i = 0; i < N; ++i) edges[i].clear();
      v_left  = VI(N + 1, -1);
      v_right = VI(M + 1, -1);
      gophers.clear();
      holes.clear();
      hi = (V*S)*(V*S);
      for(int i = 0; i < N; ++i) {
         scanf("%lf%lf",&p.first,&p.second);
         gophers.push_back(p);
      }
      for(int i = 0; i < M; ++i) {
         scanf("%lf%lf",&p.first,&p.second);
         holes.push_back(p);
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            if(dist(gophers[i],holes[j]) < hi) 
               edges[i].push_back(j);
         }
      }
      printf("%d\n",match());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

