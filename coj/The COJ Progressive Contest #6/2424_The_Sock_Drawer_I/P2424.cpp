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

const int MAXN = 32;
int C[42];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, K, ma;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> K;
      memset(C, 0, sizeof(C));
      ma = 0;
      for(int i = 0; i < K; ++i) {
         cin >> C[i];
         ma = max(ma, C[i]);
      }
      // the minimum number of socks she has to take to be sure that 
      // she has 2 of the same color
      int x = K + 1;
      // the minimum number of socks she has to take to be sure that she 
      // has 2 socks of different colors
      int y = ma + 1;
      cout << "Case " << tc << ": " << x << " " << y << endl;
   }
   return 0;
}
