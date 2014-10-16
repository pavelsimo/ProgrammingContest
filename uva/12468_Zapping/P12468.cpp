/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12468  C++  "Math, Ad hoc" */
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {  
   int n, m;
   while(2 == scanf("%d%d",&n,&m)) {
      if(n < 0 && m < 0) break;
      printf("%d\n",min(abs(n-m), 100 + min(n,m) - max(n,m)));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
