#include<stdio.h>
int r,c,t,n,a[1002][1002];
int main(){
   scanf("%d",&t);
   while(t--){
      r=c=0;
      scanf("%d",&n);
      while(r++ < n)
         c=0, while(c < r+1) scanf("%d",&a[r][c]);
   }
   return 0;
}
