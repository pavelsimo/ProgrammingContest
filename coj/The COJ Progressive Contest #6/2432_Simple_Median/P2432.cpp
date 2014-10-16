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
int X[MAXN];

int main(int argc, char *argv[]) { 
   int N;
   while(scanf("%d",&N)) {
      if(!N) break;
      for(int i = 0; i < N; ++i)
         scanf("%d",&X[i]);
      sort(X, X + N);
      if(N & 1) {
         printf("%.1lf\n",double(X[N/2]));
      } else {
         printf("%.1lf\n",double(X[(N-1)/2] + X[(N-1)/2 + 1]) / 2.0);
      }
   }
   return 0;
}
