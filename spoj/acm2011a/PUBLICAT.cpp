/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PUBLICAT C++ "Graph Theory, BFS" */
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

typedef vector<int> VI;

map<string, int> m_id;
VI adj[102];
int D[102];

void bfs() {
   memset(D,-1,sizeof(D));
   queue<int> Q;
   Q.push(0);
   D[0] = 0;
   while(!Q.empty()) {
      int cur = Q.front(); Q.pop();
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         if(D[nxt] < 0) {
            D[nxt] = D[cur] + 1;
            Q.push(nxt);
         }
      }
   }
}

int main(int argc, char *argv[]) {
   string buf, s;
   int TC, N, K;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);
      m_id.clear();
      for(int i = 0; i < 102; ++i) 
         adj[i].clear();
      K = 0;
      m_id["ORIZONDO"] = 0;
      while(N-- > 0) {
         vector<string> authors;
         getline(cin,buf);
         istringstream in(buf);
         while(in >> s) {
            if(m_id.count(s)==0) m_id[s] = ++K;
            authors.push_back(s);
         }
         for(int i = 0; i < sz(authors); ++i) {
            int u = m_id[authors[i]];
            for(int j = 0; j < sz(authors); ++j) {
               if(i == j) continue;
               int v = m_id[authors[j]];
               adj[u].push_back(v);
               adj[v].push_back(u);
            }
         }
      }
      bfs();
      int j = 0;
      for(map<string, int>::iterator it = m_id.begin(); it != m_id.end(); ++it) {
         if(j++ > 0) putchar(' ');         
         if( D[it->second] < 0)
            printf("%s",it->first.c_str());
         else
            printf("%s %d",it->first.c_str(),D[it->second]);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
