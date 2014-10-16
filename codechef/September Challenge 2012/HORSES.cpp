#include <cstdio>
#include <algorithm>

using namespace std;

int a[5002];
const int INF = 2000000000;

int main(int argc, char *argv[]) {  
   int TC, N, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%d",&);
      sort(a, a + N);
      res = INF;
      for(int i = 1; i < N; ++i)
         res = min(res, a[i] - a[i-1]);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
