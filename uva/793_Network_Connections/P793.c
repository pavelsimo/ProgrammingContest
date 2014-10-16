/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  793  C++  "Disjoint Sets" */
#include <stdio.h>
#include <string.h>

char buf[1024];
int parent[10000002];

int find_set(int x) {
   if(parent[x] == x) 
      return x;
   return parent[x] = find_set(parent[x]);
}

int union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return 1;
   parent[x] = y;
   return 0;
}

int main(int argc, char *argv[]) {  
   int TC, i, n, x, y, success, unsuccess;
   char ch;
   gets(buf);
   sscanf(buf,"%d",&TC);
   gets(buf);
   while(TC-- > 0) {
      gets(buf);
      sscanf(buf,"%d",&n);
      for(i = 1; i <= n; ++i) parent[i] = i;
      success = unsuccess = 0;
      while(gets(buf) && sscanf(buf,"%c %d %d",&ch, &x, &y) == 3) {
         if(ch == 'c') {
            union_set(x, y);
         } else {
            if(find_set(x) == find_set(y)) success++;
            else unsuccess++;
         }
      }
      printf("%d,%d\n",success,unsuccess);
      if(TC) printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
