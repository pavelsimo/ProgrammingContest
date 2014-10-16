/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10041  C++  "Ad Hoc, Math" */
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

const int INF = 0x3f3f3f3f;
int A[600], N;

int f(int x) {
   int res = 0;
   for(int i = 0; i < N; ++i)
      res+=abs(A[i]-x);
   return res;
}

int main(int argc, char *argv[]) {
   int TC, M;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%d",&A[i]);
      M = N/2;
      nth_element(A,A+M,A+N);
      printf("%d\n",f(A[M]));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
