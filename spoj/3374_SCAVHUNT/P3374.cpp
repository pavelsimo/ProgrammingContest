/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SCAVHUNT C++ "Graph Theory" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

VVI adj;
map<string,int> m_id;
map<int,string> m_str;
int in_degree[350];
bool seen[350];

void dfs(int cur) {
   if(!seen[cur]) {
      puts(m_str[cur].c_str());
      seen[cur] = true;
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         dfs(nxt);  
      }
   }
}

int main(int argc, char *argv[]) {  
   int TC, S, k;
   string s, u, v;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin,s);
      sscanf(s.c_str(),"%d",&S);
      adj = VVI(S+1);
      m_id.clear();
      m_str.clear();
      memset(in_degree,0,sizeof(in_degree));
      memset(seen,false,sizeof(seen));
      k = 0;
      for(int i = 0; i < S-1; ++i) {
         getline(cin,s);
         istringstream in(s);
         in >> u >> v;
         if(m_id.count(u)==0) {
            m_id[u] = k;
            m_str[k] = u;
            k++;
         }
         if(m_id.count(v)==0) {
            m_id[v] = k;
            m_str[k] = v;
            k++;
         }
         adj[m_id[u]].push_back(m_id[v]);
         in_degree[m_id[v]]++;
      }
      printf("Scenario #%d:\n",tc);
      for(int i = 0; i < k; ++i) {
         if(in_degree[i]==0) {
            dfs(i);
            break;
         }
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
