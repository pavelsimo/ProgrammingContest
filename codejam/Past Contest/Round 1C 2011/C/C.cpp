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

const int MAXN = 10010;
int a[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, L, H;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
        scanf("%d%d%d",&N,&L,&H);
        for(int i = 0; i < N; ++i)
           scanf("%d",a+i);
        printf("Case #%d: ",tc);
        bool found = false;
        int i;
        for(i = L; i <= H; ++i) {
           int j;
           for(j = 0; j < N; ++j) {
              if(i%a[j]==0 || a[j]%i==0);
              else break;
           }
           if(j==N) {
              found = true;
              break;
           }
        }
        if(found) printf("%d\n",i);
        else printf("NO\n");
   }
   return 0;
}

