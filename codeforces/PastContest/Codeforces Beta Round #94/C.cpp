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

const int N = 8;
int memo[12][12][128], R[128], C[128], ind;
char board[12][12];
int dr[] = {+0,+1,+0,-1,+0,+1,-1,+1,-1};
int dc[] = {+0,+0,+1,+0,-1,+1,-1,-1,+1};

int isinside(int r, int c) {
   return r >= 0 && r < N && c >= 0 && c < N;
}

int check(int r, int c, int d) {
   for(int i = 0; i < ind; ++i)
      if(r == R[i] + d && c == C[i]) 
         return 0;
   return 1;
}

int rec(int i, int j, int k) {
   if(k > 100 || !check(i,j,k)) return 0;
   if(i == 0 && j == 7) return 1;
   int &res = memo[i][j][k];
   if(res != -1) return res;
   res = 0;
   for(int d = 0; d < 9; ++d) {
      int ni = i + dr[d];
      int nj = j + dc[d];
      if(isinside(ni,nj)) {
         if(check(ni,nj,k)) 
            res|=rec(ni,nj,k+1);   
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   memset(memo,-1,sizeof(memo));
   ind = 0;
   for(int i = 0; i < N; ++i) {
      gets(board[i]);
      for(int j = 0; j < N; ++j) {
         if(board[i][j] == 'S') {
            R[ind] = i;
            C[ind] = j;
            ind++;
         }
      }
   }
   if(rec(7,0,0)) puts("WIN");
   else puts("LOSE");
   return 0;
}

