/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10469  C++  "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   llong N, M;
   while(scanf("%lld%lld",&N,&M)==2)
      printf("%lld\n",N^M);
   return 0;
}
/* @END_OF_SOURCE_CODE */
