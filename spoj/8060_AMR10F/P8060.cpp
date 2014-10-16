/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ AMR10F C++ "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   int TC, N, A, D, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&N,&A,&D);
      res = A;
      for(int i = 1; i < N; ++i)
         res+=(A+D*i);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
