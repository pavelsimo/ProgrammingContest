/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10515  C++  "Math, Big Mod, Power" */
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

const int MOD = 10;

int power(int b, int x) {
   if(!x) return 1;
   if(x & 1) {
      return ((b % MOD) * (power(b, x - 1) % MOD)) % MOD;
   } else {
      int a = power(b, x >> 1) % MOD;
      return (a*a) % MOD;
   }
}

int main(int argc, char *argv[]) {
   int m, n;
   while(2 == scanf("%d%d",&m,&n)) {
      if(!m && !n) break;
      printf("%d\n",power(m,n));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
