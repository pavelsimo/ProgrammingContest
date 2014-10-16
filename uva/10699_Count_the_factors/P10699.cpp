/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10699  C++  "Number Theory, Math" */
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

const int MAXN = 1000020;
int F[MAXN];

void sieve() {
   memset(F,0,sizeof(F));
   for(int i = 2; i < MAXN; ++i) {
      if(!F[i]) {
         for(int j = i; j < MAXN; j+=i)
            ++F[j];
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      printf("%d : %d\n",N,F[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
