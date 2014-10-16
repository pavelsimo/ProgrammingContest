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

typedef long long llong;

const int dj[] = {-1,+1,+0,+0};
const int di[] = {+0,+0,-1,+1};
map<pair<int, int>, pair<int,int> > P;

int bfs(int ti, int tj) {
   P.clear();
   queue<pair<int,pair<int, int> > > Q;
   Q.push(make_pair(0,make_pair(0,1)));
   P[make_pair(0, 0)] = make_pair(0, 0);
   while(!Q.empty()) {
      pair<int,pair<int, int> > cur = Q.front();
      Q.pop();
      int curi = cur.first;
      int curj = cur.second.first;
      int curd = cur.second.second;
      if(curi == ti && curj == tj) 
         return curd;
      for(int k = 0; k < 4; ++k) {
         int ni = curi + (curd * di[k]);
         int nj = curj + (curd * dj[k]);
         if(ni > 400 || ni < -400 || nj > 400 || nj < -400) continue;
         if(P.count(make_pair(ni,nj)) == 0) {
            P[make_pair(ni,nj)] = make_pair(curi, curj);
            Q.push(make_pair(ni,make_pair(nj, curd + 1)));
         }
      }
   }
   return -1;
}

int main(int argc, char *argv[]) { 
   int TC, ti, tj;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&ti, &tj);
      bfs(ti,tj);
      printf("Case #%d: ",tc);
      stack<char> S;
      pair<int,int> prev = make_pair(ti,tj);
      for(pair<int,int> cur = P[make_pair(ti,tj)]; true; cur = P[make_pair(cur.first,cur.second)]) {
         if(cur == prev) break;
         if(cur.second > prev.second) S.push('S');
         else if(cur.second < prev.second) S.push('N');
         else if(cur.first > prev.first) S.push('W');
         else if(cur.first < prev.first) S.push('E');
         prev = cur;
      }
      while(!S.empty()) {
         printf("%c",S.top());
         S.pop();
      }
      printf("\n");
   }
   return 0;
}
