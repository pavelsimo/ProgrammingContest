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

typedef long long llong;

llong X[1024], Y[1024];

int main(int argc, char *argv[]) {
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {      
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%lld%lld",&X[i],&Y[i]);
      sort(X, X + N);
      sort(Y, Y + N);
      if(N & 1) {
         puts("1");
      } else {
         printf("%lld\n",(X[N/2] - X[(N-1)/2] + 1) * (Y[N/2] - Y[(N-1)/2] + 1));
      }
   }
   return 0;
}
