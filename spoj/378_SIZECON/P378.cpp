#include<stdio.h>
int main(int argc, char *argv[]) {
   int N, ans, x;
   while(1==scanf("%d",&N)) {
      ans=0;
      while(N--) {
         scanf("%d",&x); if(x>0)ans+=x;
      }
      printf("%d\n",ans);
   }
   return 0;
}

