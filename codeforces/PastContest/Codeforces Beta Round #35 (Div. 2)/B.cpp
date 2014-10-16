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

string S[32][32];
map<string,pair<int,int> > m_id;

int main(int argc, char *argv[]) {
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n, m, k, cmd;
   cin >> n >> m >> k;
   for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
         S[i][j] = "";
   while(k-- > 0) {
      int x, y;
      string id;
      cin >> cmd;
      if(cmd == 1) {
         cin >> x >> y >> id;
         --x; --y;
         bool t = true;
         bool found = false;
         for(int i = x; i < n; ++i) {
            for(int j = t ? y: 0; j < m; ++j) {
               if(sz(S[i][j]) == 0) {
                  S[i][j] = id;
                  m_id[id] = make_pair(i,j);
                  found = true;
                  break;
               }
            }
            t = false;
            if(found) break;
         }
      } else {
         cin >> id;
         map<string,pair<int,int> >::iterator it = m_id.find(id);
         if(it == m_id.end()) {
            cout << -1 << ' ' << -1 << endl;
         } else {
            cout << it->second.first + 1 << ' ' << it->second.second + 1 << endl;
            S[it->second.first][it->second.second] = "";
            m_id.erase(it);
         }
      }
   }
   return 0;
}

 
