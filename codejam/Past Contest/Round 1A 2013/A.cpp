#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) { 
   int TC; 
   int r, t;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&r,&t);
      int res = 0, sum = 0;
      for(int rad = r; true; rad += 2) {
         sum += (rad+1)*(rad+1) - rad*rad;
         if(sum > t) break; 
         res++;
      }
      printf("Case #%d: %d\n",tc,res);
   }
   return 0;
}
