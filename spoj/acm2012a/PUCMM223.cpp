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

struct State {
  int i, j, type; 
  State(int _i = 0, int _j = 0, int _type = 0) : 
      i(_i), j(_j), type(_type) {}
};

int n, m, D[32][32][2];
string board[32];
int di[] = {+0,-1,+0,+1,+0};
int dj[] = {+1,+0,-1,+0,+0};

int bfs1(int ai, int aj, int bi, int bj) {
   memset(D, -1, sizeof(D));
   queue<State> Q;
   Q.push(State(ai,aj,1));
   D[ai][aj][1] = 0;
   while(!Q.empty()) {
      State cur = Q.front();
      Q.pop();
      if(cur.i == bi && cur.j == bj) 
         return D[cur.i][cur.j][cur.type];
      for(int d = 0; d < 4; ++d) {
         int ni = cur.i + di[d];
         int nj = cur.j + dj[d];
         if(ni < 0 || ni >= n || nj < 0 || nj >= m 
            || board[ni][nj] == '#' || D[ni][nj][cur.type] >= 0) continue;
         D[ni][nj][cur.type] = D[cur.i][cur.j][cur.type] + 1;
         Q.push(State(ni,nj,cur.type));
      }
   }
   return -1;
}


int main(int argc, char *argv[]) {
   int ai, aj, bi, bj;
   while(cin >> n >> m) {
      if(!n && !m) break;
      for(int i = 0; i < n; ++i) {
         cin >> board[i];
         for(int j = 0; j < m; ++j) {
            if(board[i][j] == 'a') {
               ai = i;
               aj = j;
            } 
            if(board[i][j] == 'b') {
               bi = i;
               bj = j;
            }
         }
      }
      
      cout << bfs1(ai, aj, bi, bj) << endl;
      for(int k = 0; k < n; ++k) {
         for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
               printf("%02d ", D[i][j][k]);
            }
            cout << endl;
         }
         cout << endl;
      }
   }
   return 0;
}

