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

bool adj[10][10];

int main(int argc, char *argv[]) {
   memset(adj,false,sizeof(adj));
   int M, u, v;
   cin >> M;
   for(int i = 0; i < M; ++i) {
      cin >> u >> v;
      --u; --v;
      adj[u][v] = true;
      adj[v][u] = true;
   }
   for(int i = 0; i < 5; ++i) {
      for(int j = i + 1; j < 5; ++j) {
         for(int k = j + 1; k < 5; ++k) {
            if((adj[i][j] && adj[j][k] && adj[k][i]) || 
                  (!adj[i][j] && !adj[j][k] && !adj[k][i])) {
               puts("WIN");
               return 0;
            }
         }
      }
   }
   puts("FAIL");
   return 0;
}

