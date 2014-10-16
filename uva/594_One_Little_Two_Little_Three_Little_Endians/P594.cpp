/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  594  C++  "Ad Hoc, Bits" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

char s[34];

int main(int argc, char *argv[]) {
	int n, res;
   while(1 == scanf("%d\n", &n)) {
      for(int i = 0; i < 32; ++i) {
         if(n & (1<<i)) s[i] = '1';
         else s[i] = '0';
      }
      for(int i = 0; i < 32; i += 8)
         reverse(s + i, s + i + 8);
      res = 0;
      for(int i = 0; i < 32; ++i)
         res = res * 2 + (s[i] - '0');
      printf("%d converts to %d\n", n, res);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
