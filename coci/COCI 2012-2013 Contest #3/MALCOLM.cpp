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

vector<int> A[22];
int N, K;

llong solve(int id_grp) {
   llong res = 0LL;
   llong cnt = 0LL;
   int prev = 0;
   bool ok = true;
   for(int i = 0; i < sz(A[id_grp]) && ok; ++i) {
      int j = int(lower_bound(all(A[id_grp]), A[id_grp][i] + K) - A[id_grp].begin());
      if(A[id_grp][j] > A[id_grp][i] + K) --j;
      if(j >= sz(A[id_grp]) - 1) j = sz(A[id_grp]) - 1, ok = false;
      llong len = j - i + 1;
      llong len2 = max(0, prev - i + 1);
      cnt += len2 * (len2 - 1) / 2LL;
      res += len  * (len - 1)  / 2LL;
      prev = j;
   }
   res -= cnt;
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> K;
   string s;
   for(int i = 0; i < N; ++i) {
      cin >> s;
      A[sz(s)].push_back(i + 1);
   }
   llong res = 0LL;
   for(int i = 2; i <= 20; ++i)
      res += solve(i);
   cout << res << endl;
   return 0;
}

