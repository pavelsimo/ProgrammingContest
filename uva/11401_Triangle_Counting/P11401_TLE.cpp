/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  530  C++  "Math, Combinations" */
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

int main(int argc, char *argv[]) {
   int n, res;
   while(1 == scanf("%d",&n)) {
      if(!n) break;
      res = 0;      
      for(int i = 3; i <= n; ++i) {
         int lo = 2;
         int hi = i - 1;
         int sum = 0;
         while(lo < hi) {
            //printf("%d %d\n",lo,hi);
            sum+=(hi-lo);
            lo++;
            hi--;
         }
         res+=sum;
         printf("%d = %d (%d)\n",i,res,sum);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
