/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11966  C++  "Graph Theory, DFS" */
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

typedef pair<double,double> Point;
typedef vector<int> VI;

const int MAXN = 1002;
int N;
Point p[MAXN];
VI adj[MAXN];
bool seen[MAXN];

void dfs(int cur) {
   if(!seen[cur]) {
      seen[cur] = true;  
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         dfs(nxt);  
      }
   }
}

double dist(Point a, Point b) {
   double dx = a.first-b.first;
   double dy = a.second-b.second;
   return dx*dx + dy*dy;
}

int main(int argc, char *argv[]) {
   int TC, res;
   double D;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%lf",&N,&D);
      memset(seen,false,sizeof(seen));
      for(int i = 0; i <= N; ++i) adj[i].clear();
      for(int i = 0; i < N; ++i)
         scanf("%lf%lf",&p[i].first,&p[i].second);
      for(int i = 0; i < N; ++i) {
         for(int j = i + 1; j < N; ++j) {
            if(dist(p[i],p[j]) > D*D) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
         }
      }
      res = 0;
      for(int i = 0; i < N; ++i) {
         if(!seen[i]) {
            dfs(i);
            res++;
         }
      }
      printf("Case %d: %d\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
