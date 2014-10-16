/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FORMALLA C++ "Ad Hoc" */
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

llong Y[55];
PII P[55];
int N;

double f(double y) {
   double res = 0;
   for(int i = 0; i < N; ++i) {
      llong x1 = P[i].first;
      llong y1 = P[i].second;
      for(int j = i + 1; j < N; ++j) {
         llong x2 = P[j].first;
         llong y2 = P[j].second;
         if(x1 == x2) {
            res = max(res,fabs(y2-y1));
         } else {
            res = max(res,fabs(y1-y) + fabs(y2-y) + fabs(x1-x2));
         }
      }
   }
   return res;
}

double ternary_search(double a, double b) {
   double lo = a;
   double hi = b;
   for(int i = 0; i < 100; ++i) {
    double a = lo + (hi-lo)/3.0;
    double b = lo + 2.0*(hi-lo)/3.0;
    if(f(a) < f(b)) 
      hi = b;
    else 
      lo = a;
   }
   return lo + (hi - lo)/2;;   
}

int main(int argc, char *argv[]) {
   int TC;
   llong px, py, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%lld%lld",&px,&py);
         Y[i] = py;
         P[i] = PII(px,py);
      }
      sort(Y,Y+N);
      res = 100000000000000LL;
      for(int i = 1; i < N; ++i) {
         double y = ternary_search(Y[i-1],Y[i]);
         //printf("[%lld, %lld] [%lld, %lld] = %lf f(y)=%lf\n",P[i].first,P[i].second,P[j].first,P[j].second,y,f(y));
         res = min(res,llong(f(ceil(y))));
         res = min(res,llong(f(floor(y))));
      }
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
