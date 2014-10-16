/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10327  C++  "Ad Hoc, Sorting, Inversions" */
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

const int MAXN = 1002;
int A[MAXN];

int main(int argc, char *argv[]) {
   int N, res;
   while(1 == scanf("%d",&N)) {
      res = 0;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&A[i]);
         for(int j = 0; j < i; ++j) {
            if(A[j] > A[i]) res++;
         }
      }
      printf("Minimum exchange operations : %d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
