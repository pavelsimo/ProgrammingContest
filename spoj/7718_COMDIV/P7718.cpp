/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ COMDIV C++ "Math, Number Theory" */
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
#define BITCOUNT(x) __builtin_popcount(x)

const int MAXN = 1000010;
bool P[MAXN];
int D[MAXN];

void sieve() {
   for(int i = 0; i < MAXN; ++i)
      P[i] = true, D[i] = 1;
   D[0] = 0;
   P[0] = P[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(P[i]) {
         for(int j = i; j < MAXN; j+=i) {
            P[j] = false;
            int x = j;
            int cnt = 1;
            while(x % i == 0) {
               cnt++;
               x/=i;
            }
            D[j]*=cnt;
         }
         P[i] = true;
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, a, b;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&a,&b);
      printf("%d\n",D[__gcd(a,b)]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
