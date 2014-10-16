/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  713  C++  "String Manipulation, Simple Math" */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

char buf[64];

int rev(char *s) {
   char t[64];
   int n = strlen(s);
   t[n] = '\0';
   for(int i = 0; i < n; ++i)
      t[i] = s[n-i-1];
   return atoi(t);
}

int main() {
   int TC,x,y,a,b,ans;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&x,&y);
      sprintf(buf,"%d",x);
      a = rev(buf);
      sprintf(buf,"%d",y);
      b = rev(buf);
      sprintf(buf,"%d",a+b);
      printf("%d\n",rev(buf));
   }
   return 0;
}

