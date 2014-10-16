#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

int P[128], Q[128];
int main(int argc, char *argv[]) {
   int n, m, d;
   scanf("%d%d",&n,&m);
   for(int i = 0; i <= n; ++i)
      scanf("%d",&P[i]);
   for(int i = 0; i <= m; ++i)
      scanf("%d",&Q[i]);
   if(n == m) {
      d = __gcd(P[0], Q[0]);
      printf("%s%d/%d\n", P[0]*Q[0] < 0 ? "-": "", 
         abs(P[0]/d), abs(Q[0]/d));
   } else if(n > m) {
      printf("%sInfinity\n", P[0]*Q[0] < 0 ? "-": "");
   } else {
      printf("0/1\n");
   }
   return 0;
}
