/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FORMALLA C++ "Math, Geometry" */
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

typedef long long llong;
typedef pair<llong,llong> PII;

PII P[55];
int N;

llong f(int y) {
   llong res = 0;
   for(int i = 0; i < N; ++i) {
      llong x1 = P[i].first;
      llong y1 = P[i].second;
      for(int j = 0; j < N; ++j) {
         if(i==j) continue;
         llong x2 = P[j].first;
         llong y2 = P[j].second;
         if(x1 == x2) {
            res = max(res,abs(y2-y1));
         } else {
            res = max(res,abs(y1-y) + abs(y2-y) + abs(x1-x2));
         }
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   int TC;
   llong x, y, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%lld%lld",&x,&y);
         P[i] = PII(x,y);
      }
      sort(P,P+N);
      res = 100000000000000LL;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(i == j) continue;           
            llong x = f((P[i].second+P[j].second)/2);
            res = min(res,x);
         }
      }
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
