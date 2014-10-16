/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID: 4217 674 C++  "DP Coin Change" */
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

const int MAXN = 5;
const int MAXM = 7500;
int C[MAXN] = {1,5,10,25,50};
int DP[MAXM + 2];

int main() {
   memset(DP,0,sizeof(DP));
   DP[0] = 1;
   for(int j = 0; j < MAXN; ++j) {
      for(int i = 1; i <= MAXM; ++i) {
         if(i >= C[j])
            DP[i]+=DP[i-C[j]];
      }
   }
   int n;
   while(1 == scanf("%d",&n))
      printf("%d\n",DP[n]);
   return 0;
}
/* @END_OF_SOURCE_CODE */
