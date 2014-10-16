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

char board[200][200], buf[200];

#define R 0
#define L 1

int N, M;
bitset<22502> init;

struct State {
  int x, y, dir, dist;
  bitset<22502> board;
  State(int x, int y, int dir = 0, int dist = 0, bitset<22502> t) {
     board = t;
  }
};

int bfs() {
   queue<State> Q;
   Q.push(State(0,0,R,init));
   while(!Q.empty()) {
      State cur = Q.front(); Q.pop();
      if(board[cur.x][cur.y] == 'W') {
         
      }
      State nxt = cur;
      
      if(cur.dir == 'R' && cur.dir + 1 < N) {
                  
      }
   }
   return -1;   
}

int main(int argc, char *argv[]) {
   gets(buf);
   sscanf(buf,"%d%d",&N,&M);
   for(int i = 0; i < N; ++i) {
      gets(board[i]);
      for(int j = 0; j < M; ++j) {
         if(board[i][j]=='G') {
            int bit = i * M + j;
            init.set(bit,0);
         }
      }
   }
      
   
   return 0;
}

