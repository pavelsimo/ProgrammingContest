/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11933  C++  "Ad Hoc, Bitmask" */
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

int hbit(int n) {
   for(int i = 31; i >= 0; --i)
      if(n & (1<<i)) 
         return i;
   return 0;
}

int main(int argc, char *argv[]) {
   int n, a, b;
   while(scanf("%d",&n)==1) {
      if(n==0) break;
      a = b = 0;
      int m = hbit(n);
      bool flag = true;
      for(int i = 0; i <= m; ++i) {
         if(n & (1<<i)) {
            if(flag) a|=(1<<i);
            else b|=(1<<i);
            flag = !flag;
         }
      }
      printf("%d %d\n",a,b);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
