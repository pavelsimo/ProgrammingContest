/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12036  C++  "Ad Hoc" */
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

int freq[102];

int main(int argc, char *argv[]) {
   int TC, N, M, x;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      memset(freq,0,sizeof(freq));
      M = N*N;
      bool ok = true;
      for(int i = 0; i < M; ++i) {
         scanf("%d",&x);
         freq[x]++;
         if(freq[x] > N) ok = false;
      }
      printf("Case %d: ",tc);
      if(ok) puts("yes");
      else puts("no");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
