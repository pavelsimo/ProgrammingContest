/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ GIRLNBS C++ "Math, Binary Search" */
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

int G, B;

int doit(int i, int j, int d) {
   if(i > j) return false;
   while(i-- > 0) j-=d;
   return j <= d;
}

bool check(int d) {
   return doit(G,B,d) || doit(B,G,d);
}

int main(int argc, char *argv[]) {
   int lo, hi;
   while(2==scanf("%d%d",&G,&B)) {
      if(G==-1 && B==-1) break;
      lo = 1;
      hi = max(G,B);
      if(G==0 && B==0) {
         printf("0\n");
      } else {
         while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(check(mid)) 
               hi = mid;
            else
               lo = mid+1;
         }         
         printf("%d\n",lo);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
