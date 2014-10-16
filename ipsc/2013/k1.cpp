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
llong F1[MAXN], F2[MAXN];
const llong MOD = 1000000009LL;

llong f1(int i) {
   if(i < 0) return 0LL;
   return F1[i];
}

llong f2(int i) {
   if(i < 0) return 0LL;
   return F2[i];
}

llong up(int n) {
   F2[0] = 1;
   for(int i = 1; i <= n; ++i)
      F2[i] = (f2(i-1) + f2(i-2)) % MOD;
   return F2[n];
}

llong down(int n) {
   F1[0] = 1;
   for(int i = 1; i <= n; ++i)
      F1[i] = (f1(i-1) + f1(i-2) + f1(i-3) + f1(i-4)) % MOD;
   return F1[n];
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   up(100000);
   down(100000);
   int TC, n;
   cin >> TC;
   while(TC--) {
      cin >> n;
      cout << (F1[n] * F2[n]) % MOD << endl;
   }
   return 0;
}
