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

const int MAXN = 1000020;

int N;
int ans[MAXN];
int A[MAXN], G[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int sa, sg;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> A[i] >> G[i];
   sa = sg = 0;
   for(int i = 0; i < N; ++i) {
      if(sa + A[i] - sg > 500) {
         ans[i] = 0;
         sg += G[i];
      } else {
         ans[i] = 1;
         sa += A[i];
      }
   }
   if(abs(sa - sg) <= 500) {
      for(int i = 0; i < N; ++i)
         cout << (ans[i] ? 'A': 'G');
      cout << endl;
   } else {
      cout << -1 << endl;
   }
   return 0;
}
