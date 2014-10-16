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

int A[5010];
int main(int argc, char *argv[]) {
   int n, ind, res = 0;
   memset(A,0,sizeof(A));
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> ind;
      A[ind]++;
   }
   for(int i = 1; i <= n; ++i)
      if(!A[i]) res++;
   cout << res << endl;
   return 0;
}
