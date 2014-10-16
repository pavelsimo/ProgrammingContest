/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10298  C++  "String Matching, KMP" */
#include <stdio.h>
#include <string.h>
 
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
 
int nextString(char out[]) {
   fill_buffer();
   int n = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   while (buf[pos] > ' ') 
      out[n++] = buf[pos++];
   out[n] = 0;
   return n;
}

#define MAXN 1000100
int b[MAXN];
char s[MAXN];

int kmp_preprocessing() {
   int i = 0, j = -1;
   int M = strlen(s);
   b[i] = j;
   while(i < M) {
      while(j >= 0 && s[i] != s[j]) j = b[j];
      ++i; ++j;      
      b[i] = j;
   }
   return M - b[M];
}

int main(int argc, char *argv[]) {
   int n, m;
   while(1) {
      m = nextString(s);
      if(s[0]=='.') break;
      n = kmp_preprocessing();
      printf("%d\n",m/n);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
