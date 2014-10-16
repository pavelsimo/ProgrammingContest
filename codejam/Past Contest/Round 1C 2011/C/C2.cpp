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

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

template<typename INT>
INT lcm(INT a, INT b) {
   return a / gcd(a,b) * b;
}

int N;
const int MAXN = 10010;
int a[MAXN];

typedef long long llong;

int main(int argc, char *argv[]) {
   int TC, L, H;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
        scanf("%d%d%d",&N,&L,&H);
        for(int i = 0; i < N; ++i)
           scanf("%d",a+i);
        printf("Case #%d: ",tc);
        llong d = a[0];
        for(int i = 1; i < N; ++i) {
           d = lcm(llong(a[i]),d);
        }
        sort(a,a+N);
        bool found = false;
        int ans = 0;
        for(int i = N-1; i >=0; --i) {
           llong t = d/a[i];
           if(t >= L && t <= H) {
              int j;
              for(j = 0; j < N; ++j) {
                 if(t%a[j]==0 || a[j]%t==0) continue;
                 else break;
              }
              if(j==N)
                 found = true;              
           }
           if(found) {
              ans = t;
              break;
           }
        }
        if(found) printf("%d\n",ans);
        else printf("NO\n");
   }
   return 0;
}

