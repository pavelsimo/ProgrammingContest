/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12024  C++  "Simple Math, Derangement" */
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

/*
int der(int n) {
   if(n<0) return 0;
   if(n==0)return 1;
   return (n-1) *(der(n-1) + der(n-2));
}
*/

int D[] = {1, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841};
int F[] = {1 ,1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main(int argc, char *argv[]) {
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      printf("%d/%d\n",D[N],F[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
