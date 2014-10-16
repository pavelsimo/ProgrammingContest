/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12195  C++  "Ad Hoc, Music" */
#include<stdio.h>
#include<string.h>

char buf[256];

int getduration(char ch) {
   if(ch=='W') return 64;  
   if(ch=='H') return 32;
   if(ch=='Q') return 16;
   if(ch=='E') return 8;
   if(ch=='S') return 4;
   if(ch=='T') return 2;
   if(ch=='X') return 1;
   return 0;
}

int main(int argc, char *argv[]) {
   int res, n, measure, i;
   while(gets(buf)) {
      if(buf[0]=='*') break;
      res = 0;
      n = strlen(buf);
      for(i = 0; i < n; ++i) {
         if(buf[i]=='/') {
            if(measure==64) res++;
            measure = 0;
         }
         measure+=getduration(buf[i]);
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
