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

const int MAXN = 4000000;

llong S[MAXN], A[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   memset(S, 0, sizeof(S));
   llong res = 0LL;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> A[i];
   sort(A, A + n);
   S[n] = 0;
   for(int i = n - 1; i >= 0; --i) {
      res += A[i];
      S[i] = res;
   }
   for(int i = 1; i < n; i*=4LL) {
      res += S[n - i];
   }
   cout << res << endl;
   return 0;
}
