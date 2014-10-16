/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12032  C++  "Ad Hoc, Math" */
#include <stdio.h>
#include <string.h>

#define BUFSIZE (6291456)
int bEOF;
int pos, end;
char buf[BUFSIZE+64];

void fill_buffer() {
   int rem = end - pos;
   if (rem < 64 && !bEOF) {
      memcpy(buf, buf+pos, rem);
      int nread = fread(buf + rem, 1, BUFSIZE - rem, stdin);
      if (!nread) bEOF = 1;
      pos = 0;
      end = rem + nread;
   }
}
 
int nextPosInt() {
   fill_buffer();
   int res = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   while (buf[pos] > ' ') 
      res = res*10+(buf[pos++]&15);
   return res;
}
 
int nextInt() {
   fill_buffer();
   int res = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   int neg = 0;
   switch (buf[pos]) {
      case '-': neg = 1;
      case '+': ++pos;
   }
   while (buf[pos] > ' ') 
      res = res*10+(buf[pos++]&15);
   return neg ? -res : res;
}

int max(int a, int b) {
   return a > b ? a: b;
}

int main() {
   int TC, N ,tc, u, i, dif, prev, mis, add;
   TC = nextInt();
   for(tc = 1; tc <= TC; ++tc) {
     N = nextInt();
     prev = mis = add = 0;
     for(i = 0; i < N; ++i) {
         u = nextInt();
         dif = u+add-prev;
         if(i==0) {
            mis = dif , add = 1;
         } else {
             if(mis<dif) {
                 mis = max(mis+1,dif-add);
                 add = (mis==dif-add);
             }
             else if(mis==dif)++add;
         }
         prev = u;
     }
     printf("Case %d: %d\n",tc,mis);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
