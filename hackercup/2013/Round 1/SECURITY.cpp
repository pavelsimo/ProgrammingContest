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

typedef vector<int> VI;

const int MAXN = 102;
VI v_left, v_right, edges[MAXN];
bool seen[MAXN];
int N;

bool dfs(int cur) {
   if(seen[cur]) return false;
   seen[cur] = true;
   for(int v = 0; v < sz(edges[cur]); ++v) {
      int nxt = edges[cur][v];
      if(v_right[nxt]==-1 || dfs(v_right[nxt])) {
         v_left[cur] = nxt;
         v_right[nxt] = cur;
         return true;
      } 
   }
   return false;
}

int bipartite_matching() {
   int res = 0;
   bool aug_path_found;
   while(true) {
      memset(seen,false,sizeof(seen));
      aug_path_found = false;
      for(int i = 0; i < N; ++i) {
          if(v_left[i] == -1 && dfs(i))
             aug_path_found = true;
      }
      if(!aug_path_found) break;
   }
   for(int i = 0; i < N; ++i) {
      if(v_left[i]!=-1)
         res++;
   }
   return res;
}

bool ok(const string &a, const string &b) {
   for(int i = 0; i < sz(a); ++i) {
      if(a[i] == '?' || b[i] == '?') continue;
      if(a[i] != b[i])  
         return false;
   }
   return true;
}


int get_bpm(int m, const string &k1, const string &k2) {
   memset(seen,false,sizeof(seen));
   for(int i = 0; i < MAXN; ++i) edges[i].clear();
   N = m;
   v_left  = VI(m, -1);
   v_right = VI(m, -1);
   int l = sz(k1) / m;
   for(int i = 0; i < sz(k1); i+=l) {
      string s1 = k1.substr(i, l);
      for(int j = 0; j < sz(k2); j+=l) {
         string s2 = k2.substr(j, l);
         if(ok(s1,s2))
            edges[i/l].push_back(j/l);
      }
   }   
   return bipartite_matching();
}

int main(int argc, char *argv[]) { 
   int TC, m;
   string k1, k2;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> m >> k1 >> k2;
      cout << "Case #" << tc << ": ";
      if(m == get_bpm(m, k1, k2)) {
         bool found = true;
         for(int i = 0; i < sz(k1); ++i) {
            if(k1[i] == '?') {
               for(k1[i] = 'a'; k1[i] <= 'f'; ++k1[i])
                  if(get_bpm(m, k1, k2) == m) break;
               if(k1[i] > 'f') {
                  cout << "IMPOSSIBLE" << endl;
                  found = false;
                  break;
               }
            }
         }
         if(found) cout << k1 << endl;
      } else {
         cout << "IMPOSSIBLE" << endl;
      }
   }
   return 0;
}
