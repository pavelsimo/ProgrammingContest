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

const int MAXN = 32, N = 4;
const int X_WON = 0, O_WON = 1, DRAW = 2, NOT_COMPLETE = 3;

char buf[MAXN];
char board[MAXN][MAXN];
int di[] = {+1,+0,-1,+0,+1,-1,+1,-1};
int dj[] = {+0,+1,+0,-1,+1,-1,-1,+1};

int solve() {
   int pcnt = 0;
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
         if(board[i][j] == '.') pcnt++;
         for(int dir = 0; dir < 8; ++dir) {
            int ocnt = 0, xcnt = 0;
            int k;
            for(k = 0; k < 4; ++k) {
               int ni = i + k * di[dir];
               int nj = j + k * dj[dir];
               if(ni >= N || ni < 0 || nj >= N || nj < 0) break;
               if(board[ni][nj] == 'T' || board[ni][nj] == 'X') xcnt++;
               if(board[ni][nj] == 'T' || board[ni][nj] == 'O') ocnt++;
            }
            if(k >= N) {
               if(xcnt == N) return X_WON;
               if(ocnt == N) return O_WON;
            }
         }
      }
   }
   return pcnt == 0 ? DRAW: NOT_COMPLETE;
}

int main(int argc, char *argv[]) { 
   int TC;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      for(int i = 0; i < N; ++i)
         gets(board[i]);
      printf("Case #%d: ",tc);
      int ans = solve();
      if(ans == X_WON) printf("X won");
      else if(ans == O_WON) printf("O won");
      else if(ans == DRAW) printf("Draw");
      else printf("Game has not completed");
      printf("\n");
      gets(buf);
   }
   return 0;
}
