/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10227  C++  "Disjoint Sets" */
#include <cstdio>
#include <cstring>

int P, T, seen[102][102];
char buf[128];
int parent[102], size;

int find_set(int x) {
   if(parent[x] == x) 
      return x;
   return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return true;
   parent[x] = y;
   size--;
   return false;
}

bool same_opinion(int i, int j) {
   for(int k = 0; k < T; ++k)
      if(seen[i][k] != seen[j][k])
         return false;
   return true;
}

int main(int argc, char *argv[]) {
   int TC, u, v;
   gets(buf);
   sscanf(buf,"%d",&TC);
   gets(buf);
   while(TC-- > 0) {
      memset(seen, 0, sizeof(seen));
      gets(buf);
      sscanf(buf,"%d%d",&P,&T);
      while(gets(buf) && sscanf(buf,"%d%d",&u,&v) == 2) {
         --u; --v;
         seen[u][v] = 1;
      }
      size = P;
      for(int i = 0; i < P; ++i) 
         parent[i] = i;
      for(int i = 0; i < P - 1; ++i) {
         for(int j = i + 1; j < P; ++j) {
            if(same_opinion(i, j)) {
               union_set(i, j);
            }
         }
      }
      printf("%d\n",size);
      if(TC) printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
