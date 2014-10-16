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

int DP[256][256];

int main(int argc, char *argv[]) {
   int n, m, S, G, D;
   while(cin >> n) {
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            cin >> DP[i][j];
         }
      }      
      cin >> m;
      for(int k = 0; k < n; ++k) {
         for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
               DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);     
            }
         }
      }
      while(m-- > 0) {
         cin >> S >> G >> D;
         cout << DP[S][G] + DP[G][D] << ' ' << DP[S][G] + DP[G][D] - DP[S][D] << endl;
      }
   }
   return 0;
}

