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

#define i first
#define j second
typedef pair<int,int> State;

int n, m, D[2010][2010], best, R[12], C[12], k, ai, aj;
int di[] = {+1,-1,+0,+0};
int dj[] = {+0,+0,+1,-1};

void bfs() {
   memset(D, -1, sizeof(D));
   queue<State> Q;
   best = -1;
   for(int i = 0; i < k; ++i) {
      Q.push(make_pair(R[i],C[i]));
      D[R[i]][C[i]] = 0;
   }
   while(!Q.empty()) {
      State cur = Q.front();
      Q.pop();
      if(D[cur.i][cur.j] > best) {
         best = D[cur.i][cur.j];
         ai = cur.i;
         aj = cur.j;
      }
      for(int d = 0; d < 4; ++d) {
         int ni = cur.i + di[d];
         int nj = cur.j + dj[d];
         if(ni > n || ni < 1 || nj > m || nj < 1 || D[ni][nj] >= 0) continue;
         D[ni][nj] = D[cur.i][cur.j] + 1;
         Q.push(make_pair(ni,nj));
      }
   }
}

int main(int argc, char *argv[]) {
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d%d%d",&n,&m,&k);
   best = 0;
   for(int i = 0; i < k; ++i)
      scanf("%d%d",&R[i],&C[i]);
   bfs();
   printf("%d %d\n",ai,aj);
   return 0;
}

 
