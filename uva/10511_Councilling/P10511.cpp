/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10511  C++  "Graph Theory, Max Flow, Edmonds-Karp" */
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

typedef long long llong;

const int INF = 0x3f3f3f3f;
const int n_source = 0;
const int n_sink   = 1;

typedef vector<int> VI;
typedef vector<VI> VVI;

int N;
VVI adj, flow, cap;
VI d, p;

int mf_edmonds_karp(int src, int dst) {
   flow = VVI(N, VI(N, 0));
   p = VI(N, 0);
   queue<int> q;
   int f = 0;
   while(1) {
      d = VI(N, 0);
      d[src] = INF;
      q.push(src);
      while(!q.empty()) {
         int cur = q.front(); q.pop();
         for(int i = 0; i < sz(adj[cur]); ++i) {
            int nxt = adj[cur][i];
            if(d[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
               p[nxt] = cur;
               q.push(nxt);
               d[nxt] = min(d[cur], cap[cur][nxt] - flow[cur][nxt]);
            }
         }
      }
      if(d[dst] == 0) break;
      for(int cur = dst; cur != src; cur = p[cur]) {
         flow[p[cur]][cur] += d[dst];
         flow[cur][p[cur]] -= d[dst];
      }
      f += d[dst];
   }
   return f;
}

string buf;
map<int, string> m_club_val, m_party_val, m_rdent_val;
map<string, int> m_club_id, m_party_id, m_rdent_id;
map<int, vector<int> > m_adj;
map<int, int> m_get_party;
int nclub, nparty, nrdent;

inline void add_rdent(const string &s) {
   if(!m_rdent_id.count(s)) {
      m_rdent_id[s] = nrdent;
      m_rdent_val[nrdent] = s;
      nrdent++;
   }
}

inline void add_club(const string &s) {
   if(!m_club_id.count(s)) {
      m_club_id[s] = nclub;
      m_club_val[nclub] = s;
      nclub++;
   }
}

inline void add_party(const string &s) {
   if(!m_party_id.count(s)) {
      m_party_id[s] = nparty;
      m_party_val[nparty] = s;
      nparty++;
   }
}

inline void clear() {
   m_club_id.clear(); 
   m_party_id.clear(); 
   m_rdent_id.clear();
   m_adj.clear(); 
   m_get_party.clear();
   m_club_val.clear();
   m_party_val.clear();
   m_rdent_val.clear();
   nrdent = nparty = nclub = 0;   
}

inline int get_party_id(int x) {
   return 2 + x;
}

inline int get_rdent_id(int x) {
   return 2 + nparty + x;
}

inline int get_club_id(int x) {
   return 2 + nparty + nrdent + x;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, res;
   string resident, party, club;
   getline(cin, buf);
   sscanf(buf.c_str(),"%d",&TC);
   getline(cin, buf);
   while(TC-- > 0) {
      clear();
      while(getline(cin, buf) && sz(buf)) {
         istringstream in(buf);
         in >> resident >> party;
         add_party(party); 
         add_rdent(resident);
         int u = m_rdent_id[resident];
         m_get_party[u] = m_party_id[party];
         while(in >> club) {
            add_club(club);
            int v = m_club_id[club];
            m_adj[u].push_back(v);
         }
      }
      N = nclub + nrdent + nparty + 10;
      cap = VVI(N, VI(N, 0));
      adj = VVI(N);
      foreach(it, m_get_party) {
         int rdent_id = get_rdent_id(it->first);
         int party_id = get_party_id(it->second);
         adj[n_source].push_back(party_id);
         adj[party_id].push_back(n_source);

         adj[party_id].push_back(rdent_id);
         adj[rdent_id].push_back(party_id);

         cap[n_source][party_id] = max(1, nclub % 2 == 0 ? nclub / 2 - 1: nclub / 2);
         cap[party_id][rdent_id] = 1;
      }
      foreach(it, m_adj) {
         int rdent_id = get_rdent_id(it->first);
         vector<int> l_clubs = it->second;
         for(int i = 0; i < sz(l_clubs); ++i) {
            int club_id = get_club_id(l_clubs[i]);
            adj[rdent_id].push_back(club_id);
            adj[club_id].push_back(rdent_id);
            cap[rdent_id][club_id] = 1;
            adj[club_id].push_back(n_sink);
            adj[n_sink].push_back(club_id);
            cap[club_id][n_sink] = 1;
         }
      }
      res = mf_edmonds_karp(n_source, n_sink);
      if(res == nclub) {
         for(int i = 0; i < nclub; ++i) {
            int club_id = get_club_id(i);
            for(int j = 0; j < sz(adj[club_id]); ++j) {
               int nxt = adj[club_id][j];
               if(nxt == n_sink) continue;
               if(flow[club_id][nxt]) {
                  cout << m_rdent_val[nxt - nparty - 2] << ' ' << m_club_val[i] << '\n';
                  break;
               }
            }
         }
      } else {
         cout << "Impossible." << '\n';
      }
      if(TC) cout << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

