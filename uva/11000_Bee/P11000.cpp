/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11000  C++  "Dynamic Programming, Fibonnacci Numbers" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long llong;

const int MAXN = 102;
llong F[MAXN], M[MAXN];

int main(int argc, char *argv[]) {  
   int N;
   F[0] = 1; F[1] = 1; F[2] = 2;
   M[0] = 0; M[1] = 1; M[2] = 2;
   for(int i = 3; i < MAXN; ++i) {
      F[i] = F[i-1] + F[i-2];
      M[i] = M[i-1] + M[i-2] + 1LL;
   }
   while(1 == scanf("%d",&N)) {
      if(N == -1) break;
      printf("%lld %lld\n", M[N], M[N] + F[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
