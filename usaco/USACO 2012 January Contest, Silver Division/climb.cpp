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

struct Cow {
  llong uptime, dwtime;
  Cow(llong _uptime = 0LL, llong _dwtime = 0LL) : 
      uptime(_uptime), dwtime(_dwtime) {}
  bool operator<(const Cow &T) const {
     if(uptime != T.uptime) return uptime < T.uptime;
     return dwtime < T.dwtime;
  }
};

Cow c[25020];
int main() {
    freopen("climb.in", "r", stdin);
    freopen("climb.out", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
       scanf("%lld%lld",&c[i].uptime,&c[i].dwtime);
    sort(c,c+n);
    llong res = c[0].uptime + c[0].dwtime;
    for(int i = 1; i < n; ++i)
       res+=max(0LL,c[i].uptime-c[i-1].dwtime)+c[i].dwtime;
    printf("%lld\n",res);
    return 0;
}
