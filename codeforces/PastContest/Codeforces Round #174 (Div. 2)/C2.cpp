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

typedef long long llong;

const int MAXN = 300020;
int A[MAXN], sum[MAXN];

int main(int argc, char *argv[]) { 
   int N, SZ = 1, t, a, x, k;
   double res = 0;
   scanf("%d",&N);
   while(N-- > 0) {
      scanf("%d",&t);
      if(t == 1) {
         scanf("%d%d",&a,&x);
         a--;
         sum[a] += x;
         res += (a + 1) * x;
      } else if(t == 2) {
         scanf("%d",&k);
         res += k;
         A[SZ] = k;
         ++SZ;
      } else {
         if(SZ >= 2) {
            SZ--;
            res -= A[SZ];
            res -= sum[SZ];
            sum[SZ-1] += sum[SZ];
            A[SZ] = sum[SZ] = 0;        
         }
      }
      printf("%.6lf\n",res/SZ);
   }
   return 0;
}
