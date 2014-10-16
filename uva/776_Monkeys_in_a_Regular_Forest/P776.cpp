/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  776  C++  "Graph Theory, DFS" */
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

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<VC> VVC;
typedef vector<VI> VVI;

int N, M, cnt;
VVC board;
VVI ans;
int dr[] = {+1,-1,+0,+0,+1,-1,+1,-1};
int dc[] = {+0,+0,+1,-1,+1,-1,-1,+1};
int len[520];

void dfs(int i, int j) {
   ans[i][j] = cnt;
   for(int dir = 0; dir < 8; ++dir) {
      int nr = i + dr[dir];
      int nc = j + dc[dir];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M || ans[nr][nc]) continue;
      if(board[i][j]==board[nr][nc]) dfs(nr,nc);
   }
}

int main(int argc, char *argv[]) {
   char token;
   string buf;
   do {
      board = VVC(520);
      ans = VVI(520);
      for(N = 0; getline(cin,buf); ++N) {
         if(sz(buf)==0 || buf[0]=='%') break;
         istringstream in(buf);
         while(in >> token) {
            board[N].push_back(token);
            ans[N].push_back(0);            
         }
      }
      M = sz(board[0]);
      cnt = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            if(!ans[i][j]) {
               ++cnt;
               dfs(i,j);
            }
         }
      }
      for(int j = 0; j < M; ++j) {
         len[j] = 1;
         for(int i = 0; i < N; ++i)
            len[j] = max(len[j],sz(tostr(ans[i][j])));
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            if(j > 0) putchar(' ');
            printf("%*d",len[j],ans[i][j]);
         }
         putchar('\n');
      }
      puts("%");
   } while(sz(buf) > 0);
   return 0;
}
/* @END_OF_SOURCE_CODE */
