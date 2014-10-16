/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CANDY2 C++ "Ad Hoc" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)


struct Bag {
   int c, s, b, i;
   Bag(int _c = 0, int _s = 0, int _b = 0, int _i = 0) : 
      c(_c), s(_s), b(_b), i(_i) {}
}; 

class CmpChocolate {
public:
   bool operator()(const Bag& i, const Bag& j) {
      return i.c > j.c;
   }
};

class CmpStrawberry {
public:
   bool operator()(const Bag& i, const Bag& j) {
      return i.s > j.s;
   }
};

class CmpBanana {
public:
   bool operator()(const Bag& i, const Bag& j) {
      return i.b > j.b;
   }
};

typedef long long llong;

const int MAXN = 5010;
const llong INF = 200000000000LL;
Bag a[MAXN], b[MAXN], c[MAXN];

int main(int argc, char *argv[]) {
   int N, ans[3];
   llong C, S, B;
   while(scanf("%d",&N)==1) {
      C = S = B = 0LL;
      for(int i = 0; i < N; ++i) {
         scanf("%d%d%d",&a[i].c,&a[i].s,&a[i].b);
         a[i].i = b[i].i = c[i].i = i;
         b[i].c = c[i].c = a[i].c;
         b[i].s = c[i].s = a[i].s;
         b[i].b = c[i].b = a[i].b;
         C+=a[i].c;
         S+=a[i].s;
         B+=a[i].b;
      }
      sort(a,a+N,CmpChocolate());
      sort(b,b+N,CmpStrawberry());
      sort(c,c+N,CmpBanana());
      llong best = INF;
      for(int i = 0; i < min(10,N); ++i) {
         for(int j = 0; j < min(10,N); ++j)  {
            for(int k = 0; k < min(10,N); ++k) {
               if(a[i].i != b[j].i && a[i].i != c[k].i && b[j].i != c[k].i) {
                  llong p1 = C-a[i].c;
                  llong p2 = S-b[j].s;
                  llong p3 = B-c[k].b;
                  if(p1+p2+p3 < best) {
                     ans[0] = a[i].i;
                     ans[1] = b[j].i;
                     ans[2] = c[k].i;
                     best = p1+p2+p3;
                  }  
               }
            }      
         }
      }
      printf("%d\n%d\n%d\n",ans[0],ans[1],ans[2]);      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
