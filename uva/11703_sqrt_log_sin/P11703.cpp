/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11703  C++  "Ad Hoc, Recursion" */
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

const int MOD = 1000000;
const double PI = acos(-1.0);
const int MAXN = 1000000;
int X[MAXN + 2];

int main(int argc, char *argv[]) {
   double c1, c2, c3;
   X[0] = 1;
   for(int i = 1; i <= MAXN; ++i) {
      c1 = i-sqrt(i); c2 = log(i); c3 = sin(i) * sin(i) * i;
      X[i] = (X[(int)c1] + X[(int)c2] + X[(int)c3]) % MOD;
   }
   int N;
   while(1 == scanf("%d",&N)) {
      if(N==-1) break;
      printf("%d\n",X[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
