/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FRTNWHEL C++ "Ad Hoc" */
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

char s1[128], s2[128];

int main(int argc, char *argv[]) {
   int n, res;
   while(gets(s1)) {
      if(s1[0]=='1') break;
      gets(s2);
      n = strlen(s1);
      res = 0;
      for(int i = 0; i < n; ++i) {
         char ch1 = s1[i], ch2 = s1[i];
         int j;
         for(j = 0; j < 26; ++j) {
            if(ch1==s2[i] || ch2==s2[i]) break;
            ch1++; if(ch1 > 'Z') ch1 = 'A';
            ch2--; if(ch2 < 'A') ch2 = 'Z';
         }
         res+=j;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
