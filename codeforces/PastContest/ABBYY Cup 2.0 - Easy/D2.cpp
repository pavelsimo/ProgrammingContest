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

const int MAXN = 100002;
int msg[MAXN], key[MAXN], sum[MAXN];

int main(int argc, char *argv[]) {
   int n, m, MOD;
   cin >> n >> m >> MOD;
   for(int i = 0; i < n; ++i) 
      cin >> msg[i];
   for(int i = 0; i < m; ++i) {
      cin >> key[i];
      sum[i] = key[i];
   }
   for(int i = 1; i < m; ++i) {
      sum[i] += sum[i - 1];
   }
   for(int i = 0, j = 0; i < n; ++i) {
      if(i < n - m + 1) {
         msg[i] = (msg[i] + sum[i >= m ? m - 1: i]) % MOD;
      } else {
         msg[i] = (msg[i] + (sum[i >= m ? m - 1: i] - sum[j])) % MOD;
         ++j;
      }
   }
   for(int i = 0; i < n; ++i) {
      if(i > 0) cout << ' ';
      cout << msg[i];
   }
   cout << endl;
   return 0;
}

