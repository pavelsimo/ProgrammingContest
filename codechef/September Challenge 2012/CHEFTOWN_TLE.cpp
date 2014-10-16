#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 400002;
int A[MAXN];
set<int> S;

#define BUFSIZE (16777216)
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

int main(int argc, char *argv[]) {  
   int N, W, lo, hi, res, mi, ma;
   N = nextInt();
   W = nextInt();
   for(int i = 0; i < N; ++i)
      A[i] = nextInt();
   if(W == 1) {
      printf("%d\n",N);
   } else {
      S.clear();
      for(int i = 0; i < W - 1; ++i)
         S.insert(A[i]);
      lo = 0;
      res = 0;
      hi = W - 1;    
      while(hi < N) {
         S.insert(A[hi]);
         ma = *S.rbegin();
         mi = *S.begin();
         if(ma - mi + 1 == W) res++;
         S.erase(S.find(A[lo]));
         lo++;
         hi++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
