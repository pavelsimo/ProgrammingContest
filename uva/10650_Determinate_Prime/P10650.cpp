/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10650  C++  "Math, Prime Factor" */
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

const int MAXP = 40000;
vector<bool> P;
vector<int> primes;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
      }
   }
}

int x, y;

void print(int lo, int hi) {
   if(lo - 1 >= 0 && primes[lo-1] < x && primes[lo]-primes[lo-1] == primes[lo+1]-primes[lo]) return;
   if(hi + 1 < sz(primes) && primes[hi+1] > y && primes[hi+1]-primes[hi] == primes[lo+1]-primes[lo]) return;
   for(int i = lo; i <= hi; ++i) {
      if(i > lo) putchar(' ');
      printf("%d",primes[i]);
   }
   putchar('\n');
}

int main(int argc, char *argv[]) {
   sieve();
   int lo, hi, d;
   while(2 == scanf("%d%d",&x,&y)) {
      if(!x && !y) break;
      if(x > y) swap(x,y);
      lo = lower_bound(all(primes),x) - primes.begin();
      hi = upper_bound(all(primes),y) - primes.begin();
      for(int i = lo; i < hi - 2; ++i) {
         if(primes[i+1]-primes[i] == primes[i+2]-primes[i+1]) {
            d = primes[i+1]-primes[i];
            int src = i;
            int dst = i + 2;
            int j;
            for(j = i + 3; j < hi; ++j) {
               if(primes[j]-primes[j-1] != d) break;
               dst = j;
            }
            print(src,dst);
            i++;
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
