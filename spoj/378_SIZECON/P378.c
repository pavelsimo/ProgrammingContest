#include<stdio.h>
int main() {
   int N,r=0,x; 
   scanf("%d",&N);
   while(N--)scanf("%d",&x),r+=x>0?x:0;
   printf("%d\n",r);
   return 0;
}



