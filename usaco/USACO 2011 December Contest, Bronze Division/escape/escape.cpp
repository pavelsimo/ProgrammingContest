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

#define BITCOUNT(n) __builtin_popcount(n)

const int MAXN = 22;
int N, A[MAXN];

bool ok(int x, int y) {
   for(; x > 0 && y > 0; x/=10, y/=10) {
      if(x%10 + y%10 >= 10) 
         return false; 
   }
   return true;
}

bool check(int mask) {
   int sum = 0;
   for(int i = 0; i < N; ++i) {
      if(mask & (1 << i)) {
         if(!ok(sum,A[i])) 
            return false;
         sum+=A[i];  
      }
   }
   return true;
}

int main() {
   //freopen("escape.in", "r", stdin);
   //freopen("escape.out", "w", stdout);
   int res;
   scanf("%d",&N);
   for(int i = 0; i < N; ++i)
      scanf("%d",&A[i]);
   int S = (1 << N);
   res = 0;
   for(int i = 1; i < S; ++i) {
      if(BITCOUNT(i) > res && check(i))
         res = max(res, BITCOUNT(i));
   }
   printf("%d\n",res);
   return 0;
}
