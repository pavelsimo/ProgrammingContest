/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12573  C++  "Number Theory" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int main(int argc, char *argv[]) {
   int TC;
   llong x, y;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld",&x,&y);
      llong ans = 1000000000000000000LL;
      llong am = x - y + 2;
      if(x == 0) {
         if(y == 2) printf("1\n");
         else printf("Impossible\n");  
      } else if(am == 0) {
	 if(x + 2 == y) printf("%lld\n", x + 1);
	 else printf("Impossible\n");  
      } else {
         bool found = false;
         for(llong m = 1; m * m <= am; ++m) {
            if((am % m) == 0) {
               llong d1 = am/m;
               llong d2 = m;
               if((x % d1) == y - 2) found = true, ans = min(ans, d1);
               if((x % d2) == y - 2) found = true, ans = min(ans, d2);
            }
         }
         if(found) printf("%lld\n",ans);
         else printf("Impossible\n");         
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
