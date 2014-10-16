/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11588  C++  "Ad Hoc, Frequency" */
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

char buf[128];
int freq[26];

int main(int argc, char *argv[]) { 
   int TC, N, M, C1, C2, ma, a, b;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      memset(freq, 0, sizeof(freq));
      scanf("%d%d%d%d",&N, &M, &C1, &C2);
      ma = 0;
      for(int i = 0; i < N; ++i) {
         scanf("%s",buf);
         for(int j = 0; j < M; ++j) {
            freq[buf[j] - 'A']++;
            ma = max(ma, freq[buf[j] - 'A']);
         }
      }
      a = b = 0;
      for(int i = 0; i < 26; ++i) {
         if(freq[i] == ma) a += freq[i];
         else b += freq[i];
      }
      printf("Case %d: %d\n",tc, a * C1 + b * C2);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
