/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1237  C++  "Brute Force" */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE (4*1024*1024)
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

int nextString(char out[]) {
   fill_buffer();
   int n = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   while (buf[pos] > ' ') 
      out[n++] = buf[pos++];
   out[n] = 0;
   return n;
}

#define MAXN 10002
char s[128], dict[MAXN][32];
int L[MAXN], H[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, Q, P, res, tc, i;
   TC = nextInt();
   for(tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      N = nextInt();
      for(i = 0; i < N; ++i) {
         nextString(dict[i]);
         L[i] = nextInt();
         H[i] = nextInt();
      }
      Q = nextInt();
      while(Q-- > 0) {
         P = nextInt();
         int cnt = 0;
         for(i = 0; i < N; ++i) {
            if(P >= L[i] && P <= H[i]) {
               res = i;
               cnt++;
            }
            if(cnt > 1) break;
         }
         if(cnt == 1) puts(dict[res]);
         else puts("UNDETERMINED");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
