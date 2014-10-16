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

int A[100010];

int main() {
   int TC, tc, i, res, cnt, N, k, ok;
   TC = nextInt();
   for(tc = 1; tc <= TC; ++tc) {
      res = cnt = k = 0;
      N = nextInt();
      for(i = 1; i <= N; ++i) A[i] = nextInt();
      A[0] = 0;
      for(i = 0; i < N; ++i)
         if(A[i+1]-A[i] > res) 
            res = A[i+1]-A[i];
      k = res;
      ok = 1;
      for(i = 0; i < N; ++i) {
         if(A[i+1]-A[i] > k) {
            ok = 0;
            break;
         }
         if(A[i+1]-A[i]==k) k--;
      }
      if(!ok) res++;
      printf("Case %d: %d\n",tc,res);   
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
