/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12032  C++  "Ad Hoc, Math" */
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

#define BUFSIZE (6291456)
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

const int MAXN = 100010;
int A[MAXN];

int main(int argc, char *argv[]) {
   int TC, res, cnt, N, best;
   bool ok;
   TC = nextInt();
   for(int tc = 1; tc <= TC; ++tc) {
      N = nextInt();
      for(int i = 1; i <= N; ++i)
         A[i] = nextInt();
      A[0] = 0;
      res = cnt = best = 0;
      for(int i = 0; i < N; ++i) {
         if(A[i+1]-A[i] > res)
            res = A[i+1]-A[i];
      }
      best = res;
      ok = true;
      for(int i = 0; i < N; ++i) {
         if(A[i+1]-A[i] > best) {
            ok = false;
            break;
         }
         if(A[i+1]-A[i]==best) best--;
      }
      if(!ok) res++;
      printf("Case %d: %d\n",tc,res);   
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
