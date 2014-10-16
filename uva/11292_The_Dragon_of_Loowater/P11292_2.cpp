/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11292  C++  "Binary Search" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define BUFSIZE (4*1024*1024)

const int MAXN = 20002;
int D[MAXN], C[MAXN];

bool bEOF;
int pos, end;
char buf[BUFSIZE+64];
void fill_buffer() {
   int rem = end - pos;
   if (rem < 64 && !bEOF) {
      memcpy(buf, buf+pos, rem);
      int nread = fread(buf + rem, 1, BUFSIZE - rem, stdin);
      if (!nread) bEOF = true;
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
   bool neg = false;
   switch (buf[pos]) {
      case '-': neg = true;
      case '+': ++pos;
   }
   while (buf[pos] > ' ') 
      res = res*10+(buf[pos++]&15);
   return neg ? -res : res;
}

int main(int argc, char *argv[]) {
   int N, M, res, j;
   while(true) {
      N = nextInt();
      M = nextInt();
      if(!N && !M) break;  
      for(int i = 0; i < N; ++i)
         D[i] = nextInt();
      for(int i = 0; i < M; ++i)
         C[i] = nextInt();
      sort(D,D+N);
      sort(C,C+M);
      if(N > M) {
         puts("Loowater is doomed!");
      } else {
         res = j = 0;
         bool dommed = false;
         for(int i = 0; i < N; ++i) {
            j = lower_bound(C + j, C + M, D[i]) - C;
            if(j >= M) {
               dommed = true;
               break;
            }
            res+=C[j];
            ++j;
         }
         if(dommed) puts("Loowater is doomed!");
         else printf("%d\n",res);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
