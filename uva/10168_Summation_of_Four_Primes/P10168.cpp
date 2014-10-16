/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10168  C++  "Math, Prime Numbers, Sieve" */
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
typedef vector<bool> VI;
typedef vector<llong> VL;

const int MAXN = 100000002;
VI P;
VL primes;

void sieve() {
   P = VI(MAXN + 2, true);
   for(int i = 4; i < MAXN; i+=2)
      P[i] = false;
   P[0] = false;
   P[1] = false;
   llong N = sqrt(MAXN);
   primes.push_back(2);
   for(llong i = 3; i <= N; i+=2) {
      if(P[i]) {
         primes.push_back(i);
         for(llong j = i * i; j < MAXN; j+=2*i)
            P[j] = false;
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   DEBUG(primes[sz(primes) - 1]);
   DEBUG(sz(primes));
   return 0;
}
/* @END_OF_SOURCE_CODE */
