/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PIE C++ "Binary Search" */
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

int N, F;
const long double PI = atan(1.0)*4;
const int MAXN = 10002;
double V[MAXN];

bool check(double vol) {
   int used = F+1;
   for(int i = 0; i < N; ++i) {
      double cur = V[i];
      while(cur > vol && used) {
         cur-=vol;
         used--;
      }
   }
   return used==0;
}

int main(int argc, char *argv[]) {
   int TC, r;
   double lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&N, &F);
      lo = 0.0;
      hi = 0.0;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&r);
         V[i] = PI*r*r;
         hi += V[i];
      }
      for(int i = 0; i < 100; ++i) {
         double mid = lo + (hi-lo)/2.0;
         if(check(mid)) 
            lo = mid;
         else 
            hi = mid;
      }
      printf("%.4lf\n",lo);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
