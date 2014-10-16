/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ RESN04 C++ "Ad Hoc" */
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

int N;
int main(int argc, char *argv[]) {
   int TC, stones, moves;
   scanf("%d",&TC);   
   while(TC-- > 0) {
      scanf("%d",&N);
      moves=0;
      for(int i = 1; i <= N; ++i) {
         scanf("%d",&stones);
         moves+=stones/i;
      }
      if(moves%2==0) puts("BOB");
      else puts("ALICE");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

