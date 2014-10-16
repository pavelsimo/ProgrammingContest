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

const int MAXN = 50010;
const llong INF = 50000000000000000L;
int N, M, K;
llong A[MAXN];

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&N,&M,&K);
      for(int i = 0; i < N; ++i)
         scanf("%lld",&A[i]);
   }
   return 0;
}

