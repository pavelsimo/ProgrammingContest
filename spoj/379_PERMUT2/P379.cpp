/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PERMUT2 C++ "Ad Hoc" */
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

const int MAXN = 100010;
int A[MAXN], B[MAXN];

int main(int argc, char *argv[]) {
   int N;
   while(1==scanf("%d",&N)) {
      if(N==0)break;
      for(int i = 1; i <= N; ++i) {
         scanf("%d",&A[i]);
         B[A[i]]=i;
      }
      bool ok = true;
      for(int i = 0; i < N; ++i) {
         if(A[i]!=B[i]) {
            ok = false;
            break;
         }
      }
      if(ok) puts("ambiguous");
      else puts("not ambiguous");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

