/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  782  C++  "Graph Theory, DFS" */
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

int N;
string board[64];
char border_ch;
bool seen[64][128];
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= sz(board[i]) || board[i][j]==border_ch || seen[i][j]) return;
   seen[i][j] = true;
   board[i][j] = ' ';
   for(int dir = 0; dir < 4; ++dir) {
      int nr = i + dr[dir];  
      int nc = j + dc[dir];
      if(nr >= 0 && nr < N && nc >= 0 && nc < sz(board[nr])) {
         if(board[nr][nc] == border_ch) 
            board[i][j] = '#';
      }
      dfs(nr,nc);
   }
}

int main(int argc, char *argv[]) {
   string buf;
   getline(cin,buf);
   int TC, rsrc, csrc;
   N = 0;
   sscanf(buf.c_str(),"%d",&TC);
   while(TC-- > 0) {
      while(getline(cin,buf)) {
         if(buf[0]=='_') {
            memset(seen,false,sizeof(seen));
            for(int i = 0; i < N; ++i) {
               for(int j = 0; j < sz(board[i]); ++j) {
                  if(board[i][j]=='*') {
                     rsrc = i;
                     csrc = j; 
                  } else if(!isspace(board[i][j]) && board[i][j]!='#' && board[i][j] != '_') {
                     border_ch = board[i][j];
                  }
               }
            }
            dfs(rsrc,csrc);
            for(int i = 0; i < N; ++i) {
               string line = board[i];
               line.erase(line.find_last_not_of(" ") + 1);
               puts(line.c_str());
            }
            N = 0;
            puts(buf.c_str());
         } else {
            board[N++] = buf + string(100-sz(buf),' ');
         }  
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
