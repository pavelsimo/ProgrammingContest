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

bool seen[20][20];
char buf[128], board[20][20];
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

int main(int argc, char *argv[]) {
   int N, M, res = 0;
   gets(buf);
   sscanf(buf,"%d%d",&N,&M);
   memset(seen,false,sizeof(seen));
   for(int i = 0; i < N; ++i)
      gets(board[i]);
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {
         if(board[i][j] == 'P') {
            for(int d = 0; d < 4; ++d) {
               int nr = i + dr[d];
               int nc = j + dc[d];
               if(nr < 0 || nr >= N || nc < 0 || nc >= M || seen[nr][nc]) continue;
               if(board[nr][nc] == 'W') {
                  res++;  
                  seen[nr][nc] = true;
               }
            }
         }  
      }
   }
   cout << res << endl;
   return 0;
}

