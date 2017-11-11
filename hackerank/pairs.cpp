#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int a[100002];

int main(int argc, char *argv[]) { 
   int n, k, res;
   scanf("%d%d",&n,&k);
   for(int i = 0; i < n; ++i)
      scanf("%d",&a[i]);
   sort(a, a + n);
   res = 0;
   for(int i = 0; i < n; ++i) {
      int lo = lower_bound(a + i, a + n, a[i] + k) - a;
      int hi = upper_bound(a + i, a + n, a[i] + k) - a;
      res += hi - lo;
      //fprintf(stderr,"a[i]=%d %d %d\n",a[i],a[lo],a[hi]);
   }
   printf("%d\n",res);
   return 0;
}
