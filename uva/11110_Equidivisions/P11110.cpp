/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11110  C++  "Graph Theory, DFS" */
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

int N, K;
int adj[110][110];
bool seen[110][110];
int cnt = 0, mark = 0;

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= N || seen[i][j]) 
      return; 
   if(mark == adj[i][j]) {
      seen[i][j] = true;
      cnt++;
      dfs(i + 1, j);
      dfs(i, j + 1);
      dfs(i - 1, j);
      dfs(i, j - 1);      
   }
}

int main(int argc, char *argv[]) {
   string buf;
   int u, v;
   while(getline(cin,buf)) {
      sscanf(buf.c_str(),"%d",&N);
      if(N==0) break;
      K = 0;
      memset(seen,false,sizeof(seen));
      memset(adj,0,sizeof(adj));
      for(int i = 0; i < N-1; ++i) {
         ++K;
         getline(cin,buf);
         istringstream in(buf);
         while(in >> u >> v) {
            if(u < 0 || u > N || v > N || v < 0) continue;
            --u; --v;
            adj[u][v] = K;            
         }
      }
      bool good = true;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(!seen[i][j]) {  
               mark = adj[i][j];
               cnt = 0;
               dfs(i,j);
               if(cnt != N) 
                  good = false;
            }
         }
         if(!good) break;
      }
      if(good) puts("good");
      else puts("wrong");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
