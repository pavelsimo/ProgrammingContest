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

typedef pair<int,int> Point;

int di[] = {+0,+0,+1,-1,+1,-1,+1,-1};
int dj[] = {+1,-1,+0,+0,-1,+1,+1,-1};

set<Point> P;
map<Point, int> dist;

int bfs(Point src, Point dst) {
   queue<Point> Q;
   Q.push(src);
   dist[src] = 0;
   while(!Q.empty()) {
      Point cur = Q.front();
      Q.pop();
      if(cur == dst) return dist[cur];
      for(int dir = 0; dir < 8; ++dir) {
         Point nxt = make_pair(cur.first + di[dir], cur.second + dj[dir]);
         if(P.count(nxt) == 0) continue;
         if(dist.count(nxt) == 0) {
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
         }
      }
   }
   return -1;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   Point p0, p1;
   int n, r, a, b;
   cin >> p0.first >> p0.second >> p1.first >> p1.second >> n;
   for(int i = 0; i < n; ++i) {
      cin >> r >> a >> b;
      for(int j = a; j <= b; ++j)
         P.insert(make_pair(r, j));
   }
   cout << bfs(p0, p1) << endl;
   return 0;
}

