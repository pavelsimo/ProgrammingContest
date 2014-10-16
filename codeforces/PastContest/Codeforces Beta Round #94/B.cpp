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

int degree[102];
int adj[102][102];

int main(int argc, char *argv[]) {
   int n, m, u, v, res = 0;
   cin >> n >> m;
   memset(degree,0,sizeof(degree));
   memset(adj,0,sizeof(adj));
   for(int i = 0; i < m; ++i) {
      cin >> u >> v;
      --u; --v;
      adj[u][v] = adj[v][u] = 1;
      degree[u]++; degree[v]++;
   }
   res = 0;
   while(true) {
      vector<int> a;
      for(int i = 0; i < n; ++i) {
         if(degree[i] == 1) {
            a.push_back(i);
            for(int j = 0; j < n; ++j) {
               if(adj[i][j])
                  adj[i][j] = adj[j][i] = 0;
            }            
         }
      }
      if(sz(a)==0) break;
      res++;
      for(int i = 0; i < sz(a); ++i) 
         degree[a[i]]--;
   }
   cout << res << endl;
   return 0;
}

