/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11084  C++  "Ad Hoc, Brute Force, Permutations" */
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

typedef long long llong;

char s[32], buf[32];

int main(int argc, char *argv[]) {
   llong m;
   int TC, n, d, res;  
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      sscanf(buf,"%s %d",s,&d);
      n = strlen(s);
      sort(s, s + n);
      res = 0;
      do {
         m = 0LL;
         for(int i = n - 1; i >= 0; --i)
            m = m *10 + (s[i]-'0');
         if(m % d == 0) res++;
      } while(next_permutation(s,s+n));
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
