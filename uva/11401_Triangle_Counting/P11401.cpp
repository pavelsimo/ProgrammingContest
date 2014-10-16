/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11401  C++  "Ad Hoc, Math, Triangles" */
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

const int MAXN = 1000000;
llong A[MAXN + 2];

int main(int argc, char *argv[]) {
   A[0] = A[1] = A[2] = A[3] = 0; A[4] = 1;
   for(llong i = 5, j = 2, k = 2; i <= MAXN; ++i) {
      A[i] = A[i-1] + j;
      j+=k;
      if(i % 2 == 0) k++;
   }
   int n;
   while(1 == scanf("%d",&n)) {
      if(n < 3) break;
      printf("%lld\n",A[n]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
