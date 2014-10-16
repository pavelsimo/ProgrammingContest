/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1185  C++  "Ad Hoc" */
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

const int MAXN = 10000002;
double A[MAXN];

int main(int argc, char *argv[]) {
   A[0] = 0.0;
   for(int i = 1; i <= 10000000; ++i)
      A[i] = A[i-1] + log10(i);
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      printf("%d\n",int(floor(A[N]) + 1));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
