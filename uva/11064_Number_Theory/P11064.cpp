/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11064  C++  "Number Theory, Totient Function, Divisors" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

typedef long long llong;

int div(int n) {
   int res = 0;
   for (llong i = 1; i * i <= n; ++i) { 
      if(n % i == 0) {
         res++;
         if(n/i != i) res++;
      }
   }
   return res;
}

int phi(int n) { 
   int res = n; 
   for (llong i = 2; i * i <= n; ++i) { 
      if (n % i == 0) {
         res -= res / i; 
         do {
            n /= i;
         } while (n % i == 0); 
      }
   } 
   if (n > 1) res -= res / n; 
   return res;
} 

int main(int argc, char *argv[]) {
   int n;
   while(1 == scanf("%d", &n)) {
      printf("%d\n", n - phi(n) - div(n) + 1);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
