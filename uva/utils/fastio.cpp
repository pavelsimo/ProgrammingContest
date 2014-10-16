#include <iostream>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
#include <stdio.h>
#include <string.h>
 
#define BUFSIZE (6291456)
int bEOF;
int BUFpos, BUFend;
char buf[BUFSIZE+64];
 
void fill_buffer() {
   int rem = BUFend - BUFpos;
   if (rem < 64 && !bEOF) {
      memcpy(buf, buf+BUFpos, rem);
      int nread = fread(buf + rem, 1, BUFSIZE - rem, stdin);
      if (!nread) bEOF = 1;
      BUFpos = 0;
      BUFend = rem + nread;
   }
   buf[BUFend] = 0;
} 
bool nextInt2(int &n) {
   fill_buffer();
   int res = 0;
   while (buf[BUFpos] <= ' ' && buf[BUFpos]) ++BUFpos;
   if(BUFpos==BUFend)return false;
   int neg = 0;
   switch (buf[BUFpos]) {
      case '-': neg = 1;
      case '+': ++BUFpos;
   }
   while (buf[BUFpos] > ' ') 
      res = (res<<1)+(res<<3)+(buf[BUFpos++]&15);
   n = neg ? -res : res;
   return true;
}
 
 
int nextInt() {
   fill_buffer();
   int res = 0;
   while (buf[BUFpos] <= ' ' && buf[BUFpos]) ++BUFpos;
   int neg = 0;
   switch (buf[BUFpos]) {
      case '-': neg = 1;
      case '+': ++BUFpos;
   }
   while (buf[BUFpos] > ' ') 
      res = 10*res+(buf[BUFpos++]&15);
   res = neg ? -res : res;
   return res;
}
void gen(int N)
{
    freopen("in.txt","w",stdout);
    for(int i = 0; i < N; ++i)
        printf("%d\n",rand());
}
 
int main(int argc, char** argv) {
   int N = 10000000;
   freopen("in.txt", "r", stdin);
   int n;
   long long T;
   T = clock();
   for(int i = 0; i < N; ++i) {
      n = nextInt();
   }
   printf("%0.6lfms\n",double(clock()-T)/CLOCKS_PER_SEC);
   fclose(stdin);
   freopen("in.txt", "r", stdin);
   T = clock();
   for(int i = 0; i < N; ++i) {
      nextInt2(n);
   }
   printf("%0.6lfms\n",double(clock()-T)/CLOCKS_PER_SEC);
   fclose(stdin);
   freopen("in.txt", "r", stdin);
   T = clock();
   for(int i = 0; i < N; ++i) {
      n = nextInt();
   }
   printf("%0.6lfms\n",double(clock()-T)/CLOCKS_PER_SEC);
   fclose(stdin);
   freopen("in.txt", "r", stdin);
   T = clock();
   for(int i = 0; i < N; ++i) {
      scanf("%d",&n);
   }
   printf("%0.6lfms\n",double(clock()-T)/CLOCKS_PER_SEC);
   fclose(stdin);
   return 0;
}
