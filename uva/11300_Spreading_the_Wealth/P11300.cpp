/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11300  C++  "Math, Sets" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int N, A[1000100];

int main(int argc, char *argv[]) {
   llong avg, res;
   while(1 == scanf("%d",&N)) {
      avg = res = 0LL;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&A[i]);
         avg += A[i];
      }
      avg /= N;
      DEBUG(avg);
      for(int i = 0; i < N; ++i)
         res += abs(A[i] - avg);
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
