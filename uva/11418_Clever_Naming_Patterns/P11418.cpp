/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11418  C++  "Bipartite Matching" */
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

const int MAXN = 32;
int N, M;
string problem[MAXN][26];
vector<int> L, R, edges[MAXN];
bool seen[MAXN];
vector<string> res;

bool dfs(int cur) {
   if(seen[cur]) 
      return false;
   seen[cur] = true;
   for(int i = 0; i < sz(edges[cur]); ++i) {
      int nxt = edges[cur][i];
      if(R[nxt]==-1 || dfs(R[nxt])) {
         L[cur] = nxt;
         R[nxt] = cur;
         return true;
      }
   }
   return false;
}

int match() {
   int res = 0;
   bool aug_path_found;
   while(true) {
      memset(seen,false,sizeof(seen));
      aug_path_found = false;
      for(int i = 0; i < N; ++i) {
          if(L[i] == -1 && dfs(i))
             aug_path_found = true;
      }
      if(!aug_path_found) break;
   }
   for(int i = 0; i < N; ++i) {
      if(L[i]!=-1)
         res++;
   }
   return res;
}

int main(int argc, char *argv[]) {
   int TC;
   string name;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      L.clear(); R.clear();
      res.clear();
      for(int i = 0; i < N; ++i) 
         edges[i].clear();
      for(int i = 0; i < N; ++i)
         for(int j = 0; j < 26; ++j)
            problem[i][j].clear();
      cin >> N;
      for(int i = 0; i < N; ++i) {
         cin >> M;
         L.push_back(-1); R.push_back(-1);
         for(int j = 0; j < M; ++j) {
            cin >> name;
            transform(all(name),name.begin(),::tolower);
            name[0] = toupper(name[0]);
            problem[i][name[0]-'A'] = name;
         }
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(sz(problem[i][j]) > 0) 
               edges[i].push_back(j);
         }
      }
      match();
      for(int i = 0; i < N; ++i)
         res.push_back(problem[i][L[i]]);
      sort(all(res));
      printf("Case #%d:\n",tc);
      for(int i = 0; i < sz(res); ++i) 
         puts(res[i].c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
