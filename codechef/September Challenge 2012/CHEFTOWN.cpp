#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <deque>

using namespace std;

const int MAXN = 400002;
int A[MAXN];

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

deque<int> ma_q, mi_q;

int main(int argc, char *argv[]) {  
   int N, W, lo, hi, res, mi, ma;
   N = nextInt();
   W = nextInt();
   for(int i = 0; i < N; ++i)
      A[i] = nextInt();
   if(W == 1) {
      printf("%d\n",N);
   } else {
      mi_q.clear();
      ma_q.clear();
      for(int i = 0; i < W - 1; ++i) {
         // min
         while(mi_q.size() > 0 && A[i] < A[mi_q.back()]) 
            mi_q.pop_back();
         mi_q.push_back(i);
         
         // max
         while(ma_q.size() > 0 && A[i] > A[ma_q.back()]) 
            ma_q.pop_back();
         ma_q.push_back(i);         
      }
      lo = 0;
      res = 0;
      hi = W - 1;    
      while(hi < N) {
         // min
         while(mi_q.size() > 0 && A[hi] < A[mi_q.back()]) mi_q.pop_back();
         while(mi_q.size() > 0 && mi_q.front() < lo) mi_q.pop_front();
         mi_q.push_back(hi);
         
         // max
         while(ma_q.size() > 0 && A[hi] > A[ma_q.back()]) ma_q.pop_back();
         while(ma_q.size() > 0 && ma_q.front() < lo) ma_q.pop_front();
         ma_q.push_back(hi);         

         mi = A[mi_q.front()];
         ma = A[ma_q.front()];
         if(ma - mi + 1 == W) res++;
         lo++;
         hi++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
