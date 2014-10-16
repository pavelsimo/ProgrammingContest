/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11105  C++  "Prime Numbers, Sieve" */
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
const int MAXN = 1000010;
bool prime[MAXN], seen[MAXN];
vector<llong> hp;
int DP[MAXN];

void sieve() {
   int N = 1000001;
   memset(seen,false,sizeof(seen));
   for(int i = 0; i <= N; ++i)
      prime[i] = (i % 4 == 1);
   prime[0] = prime[1] = false;
   for(llong i = 2; i <= N; ++i) {
      if(prime[i]) {
         hp.push_back(i);
         for(llong j = i+i; j <= N; j+=i)
            prime[j] = false;
      }
   }
   for(int i = 0; i < sz(hp); ++i) {
      for(int j = 0; j < sz(hp); ++j) {
         if(hp[i]*hp[j] > N) break;
         seen[hp[i]*hp[j]] = true;
      }
   }
   for(llong i = 24; i <= N; ++i) {
      DP[i] = DP[i-1];
      if(seen[i]) DP[i]++;
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int N;
   while(scanf("%d",&N) == 1) {
      if(!N) break;
      printf("%d %d\n",N,DP[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

