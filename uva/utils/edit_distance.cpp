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

const int MAXN = 1002;
int DP[MAXN][MAXN];

int main(int argc, char *argv[]) {
   string a, b;
   cin >> a >> b;
   for(int i = 0; i <= sz(a); ++i)
      DP[0][i] = i;
   for(int i = 0; i <= sz(b); ++i)
      DP[i][0] = i;
   a = " " + a;
   b = " " + b;
   for(int i = 1; i <= sz(a); ++i) {
      for(int j = 1; j <= sz(b); ++j) {
         DP[i][j] = min(DP[i][j-1] + 1, min(DP[i-1][j] + 1, 
            DP[i-1][j-1] + (a[i] != b[j])));
      }
   }
   cout << DP[sz(a)][sz(b)] << endl;
   return 0;
}

