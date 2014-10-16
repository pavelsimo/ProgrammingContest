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

const int MAXN = 102;
llong A[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> A[i];
   llong res = 0LL;
   for(int i = 0; i < N; ++i) {
      for(int j = i; j < N; ++j) {
         llong ma = 0LL;
         for(int k = i; k <= j; ++k)
            ma^=A[k];
         res = max(res, ma);
      }
   }
   cout << res << endl;
   return 0;
}
