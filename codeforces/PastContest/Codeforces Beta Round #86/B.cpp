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

typedef vector<int> VI;
typedef vector<VI> VVI;

map<string,int> m_id;
vector<string> team;
VVI adj;

#define BITCOUNT(n) __builtin_popcount(n)

int main(int argc, char *argv[]) {
   int N, M, res = 0;
   string s, u, v;
   cin >> N >> M;
   adj = VVI(N + 1);
   for(int i = 0; i < N; ++i) {
      cin >> s;   
      team.push_back(s);
   }
   sort(all(team));
   for(int i = 0; i < N; ++i)
      m_id[team[i]] = i;
   for(int i = 0; i < M; ++i) {
      cin >> u >> v;
      adj[m_id[u]].push_back(m_id[v]);
      adj[m_id[v]].push_back(m_id[u]);
   }
   for(int mask = 0; mask < (1<<N); ++mask) {
      bool found = true;
      for(int j = 0; j < N; ++j) {
         if(mask & (1<<j)) {
            for(int k = 0; k < sz(adj[j]); ++k) {
               int nxt = adj[j][k];
               if(mask & (1<<nxt)) {
                  found = false;
                  break;
               }
            }  
         }
         if(!found) break;
      }
      if(found) {
         if(BITCOUNT(mask) > BITCOUNT(res))
            res = mask;
      }
   }
   printf("%d\n",BITCOUNT(res));
   for(int i = 0; i < N; ++i) {
      if(res & (1<<i)) 
         puts(team[i].c_str());
   }
   return 0;
}

