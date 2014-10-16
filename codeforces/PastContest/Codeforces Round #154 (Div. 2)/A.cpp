#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) { 
   int n, m, k, p;
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   scanf("%d%d",&n,&m);
   k = n + m;
   p = n > m ? 0: 1;
   for(int i = 0; i < k; ++i) {
      if(i % 2 == p) {
         if(n > 0) printf("B"), --n;
         else if(m > 0) printf("G"), --m;
      } else {
         if(m > 0) printf("G"), --m;         
         else if(n > 0) printf("B"), --n;
      }
   }
   printf("\n");
   return 0;
}
