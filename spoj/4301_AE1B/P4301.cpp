/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ AE1B C++ "Ad Hoc" */
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

const int MAXN = 1010;
int A[MAXN];

int main(int argc, char *argv[]) {
   int n, k, s, res, threshold, sum;
   scanf("%d%d%d",&n,&k,&s);
   for(int i = 0; i < n; ++i)
      scanf("%d",A+i);
   sort(A,A+n);
   threshold = k*s;
   sum=res=0;
   for(int i = n-1; sum < threshold && i >= 0; --i) {
      sum+=A[i];
      res++;
   }
   printf("%d\n",res);
   return 0;
}
/* @END_OF_SOURCE_CODE */

