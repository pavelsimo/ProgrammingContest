/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10327  C++  "Ad Hoc, Sorting, Inversions" */
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

typedef vector<string> VS;

set<string> res;
VS adj[27][27];
int N, ans[27];

bool check(int letter, int problem) {
   if(sz(adj[problem][letter]) == 0) 
      return false;
   return true; 
}

void dfs(int i) {
   if(i < N) {
      for(int k = 0; k < N; ++k) {
         if(!ans[k]) {
            ans[k] = i;
            if(check(i,k))
               dfs(i + 1);
            ans[k] = 0;
         }
      }
   } else {
      for(int k = 0; k < N; ++k)
         res.insert(adj[k][ans[k]][0]);
   }
}

int main(int argc, char *argv[]) {
   string word;
   int TC, K;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      res.clear();
      for(int i = 0; i < 27; ++i) {
         for(int j = 0; j < 27; ++j) {
            adj[i][j].clear();         
         }
      }
      memset(ans,false,sizeof(ans));
      for(int i = 0; i < N; ++i) {
         cin >> K;
         for(int j = 0; j < K; ++j) {
            cin >> word;
            int nxt = tolower(word[0])-'a';
            adj[i][nxt].push_back(word);
         }
      }
      dfs(0);
      printf("Case #%d:\n",tc);
      foreach(it,res) {
         string s = *it;
         s[0] = toupper(s[0]);
         puts(s.c_str());
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
