/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ROOMNUM9 C++ "Ad Hoc" */
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

int freq[10];
char s[128];

int main(int argc, char *argv[]) {
   int TC, n, res;
   gets(s);
   sscanf(s,"%d",&TC);
   while(TC-- > 0) {
      gets(s);
      memset(freq,0,sizeof(freq));
      n = strlen(s);
      for(int i = 0; i < n; ++i) {
         int j = s[i]-'0';
         if(j==6 || j==9) {
            if(freq[6] > freq[9]) freq[9]++;
            else freq[6]++;
         } else {
            freq[j]++;
         }
      }
      res = 0;
      for(int i = 0; i < 10; ++i)
         res = max(res,freq[i]);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
