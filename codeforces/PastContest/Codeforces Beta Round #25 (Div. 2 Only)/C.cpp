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

typedef long long llong;

int D[502][502];

int main(int argc, char *argv[]) {
   int n, m, u, v, cost;
   llong sum = 0LL;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         cin >> D[i][j];
      }
   }
   for(int k = 0; k < n; ++k) {
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  
         }
      }
   }
   cin >> m;
   while(m-- > 0) {
      cin >> u >> v >> cost;
      --u; --v;
      D[u][v] = D[v][u] = min(D[u][v], cost);
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            for(int k = 0; k < 2; ++k) {
               D[i][j] = min(D[i][j], D[i][u] + D[u][v] + D[v][j]); 
               swap(u,v);
            }
         }
      }
      sum = 0LL;
      for(int i = 0; i < n; ++i) {
         for(int j = i + 1; j < n; ++j) {
            sum += D[i][j];
         }
      }
      cout << sum << ' ';
   }
   cout << endl;
   return 0;
}

