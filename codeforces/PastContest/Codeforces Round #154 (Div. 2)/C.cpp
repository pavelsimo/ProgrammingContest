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

const int MAXN = 120;
int a[MAXN], N;
int D[MAXN][100020];

struct State {
   int r, c;
   State(int _r, int _c) : r(_r), c(_c) {}
};

int dr[] = {-1, +0, +0, +1};
int dc[] = {+0, -1, +1, +0};

int bfs(int r1, int c1, int r2, int c2) {
   memset(D, -1, sizeof(D));
   queue<State> q;
   q.push(State(r1,c1));
   D[r1][c1] = 0;
   while(!q.empty()) {
      State cur = q.front(); 
      q.pop();  
      int r = cur.r, c = cur.c;
      if(r == r2 && c == c2) 
         return D[r][c];
      for(int k = 0; k < 4; ++k) {
         int nr = max(1, min(N, r + dr[k]));
         int nc = max(1, min(c + dc[k], a[nr] + 1));
         if(D[nr][nc] == -1) {
            q.push(State(nr,nc));
            D[nr][nc] = D[r][c] + 1;
         }
      }
   }   
   return -1;
}

int main(int argc, char *argv[]) { 
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int r1, c1, r2, c2;
   scanf("%d",&N);
   for(int i = 1; i <= N; ++i)
      scanf("%d",&a[i]);  
   scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
   printf("%d\n",bfs(r1, c1, r2, c2));
   return 0;
}
