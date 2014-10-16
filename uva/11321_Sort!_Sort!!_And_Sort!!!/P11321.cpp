/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11321  C++  "Sorting" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 10020;

int N, M, A[MAXN];

bool cmp(const int a, const int b) {
   if((a % M) != (b % M)) return (a % M) < (b % M);
   if((a & 1) != (b & 1)) return !(a & 1) < !(b & 1);
   if((a & 1) && (b & 1)) return a > b;
   return a < b;
}

int main(int argc, char *argv[]) {
   while(2 == scanf("%d%d",&N, &M)) {
      printf("%d %d\n", N, M);
      if(!N && !M) break;
      for(int i = 0; i < N; ++i)
	 scanf("%d",&A[i]);
      sort(A, A + N, cmp);
      for(int i = 0; i < N; ++i) 
	 printf("%d\n", A[i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

