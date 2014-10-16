/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1189  C++  "Ad Hoc, Math" */
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
#define BUFSIZE (4*1024)

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

bool seen[202];

struct State {
   int n;
   int mod;
   State(int _n, int _mod) : 
      n(_n), mod(_mod) {}
};

int highestbit(int n) {
   for(int i = 31; i >= 0; --i)
      if(n&(1<<i)) return i;
   return 0;
}

int main(int argc, char *argv[]) {
   int N;
   while(true) {
      N = nextInt();
      if(!N) break;
      memset(seen,false,sizeof(seen));
      queue<State> Q;
      Q.push(State(1,1%N));
      while(!Q.empty()) {
         State cur = Q.front(); Q.pop();
         if(cur.mod==0) {
            for(int i = highestbit(cur.n); i >= 0; --i)
               printf("%d",(cur.n & (1<<i))?1:0);
            putchar('\n');
            break;
         }
         if(seen[cur.mod]) continue;
         seen[cur.mod] = true;
         Q.push(State(cur.n<<1,(cur.mod*10)%N));
         Q.push(State((cur.n<<1)|1,(cur.mod*10+1)%N));
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
