/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ DIV C++ "Prime Numbers, Number Theory" */
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

typedef vector<int> VI;

const int MAXN = 1000020;
VI primes;
int A[MAXN], D[MAXN];
bool L[82950];

void sieve(int n) {
   for(int i = 0; i <= n; ++i)
      A[i] = i, D[i] = 1;
   for(int i = 2; i <= n; ++i) {
      int p = A[i];
      if(p==i)  {
         for(int k = i+i; k <= n; k+=i) {
            int cnt = 1;
            while(A[k]%p==0) {
               cnt++;
               A[k]/=p;
            }
            D[k]*=cnt;
         }
         if(i < 240) primes.push_back(i);
      }
   }
}

int main(int argc, char *argv[]) {
   sieve(1000005);
   for(int i = 0; i < sz(primes); ++i) {
      for(int j = 0; j < sz(primes); ++j) {
         if(i==j) continue;
         L[primes[i]*primes[j]] = true;
      }
   }
   int k = 0;
   for(int i = 1; i <= 1000000; ++i) {
      if(L[D[i]]) k++;
      if(k==9) {
         printf("%d\n",i);
         k = 0;
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

