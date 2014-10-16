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

vector<llong> a[52];
llong b[52], c[52], p[250002];
llong memo[250002], p_sum[250002];

llong go(int cur) {
   return 0;
}

int main(int argc, char *argv[]) {
   int n, m, l, x;
   cin >> n >> m;
   for(int i = 0; i < n; ++i) {
      cin >> l;
      for(int j = 0; j < l; ++j) {
         cin >> x;
         a[i].push_back(x);
      }
      llong ma = a[i][0];
      llong sum = a[i][0];
      for(int j = 1; j < l; ++j) {
         sum += a[i][j];
         ma = max(ma, sum);
      }
      b[i] = sum;
      c[i] = ma;
   }
   for(int i = 0; i < m; ++i) {
      cin >> p[i];
      --p[i];
   }
   // DEBUG
   p_sum[0] = 0;
   cout << p_sum[0]  << ' ';
   for(int i = 1; i <= m; ++i) {
      p_sum[i] += p_sum[i-1] + b[p[i]];
      cout << p_sum[i]  << ' ';
   }
   
   cout << endl;
   return 0;
}

