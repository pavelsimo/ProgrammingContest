/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12289  C++  "Ad Hoc" */
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

char buf[16];
vector<string> a;

int main(int argc, char *argv[]) {
   int TC, n, diff;
   gets(buf);
   a.push_back("one");
   a.push_back("two");
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      n = strlen(buf);
      if(n == 5) {
         printf("%d\n",3);      
      } else {
         for(int i = 0; i < sz(a); ++i) {
            diff = 0;
            for(int j = 0; j < sz(a[i]); ++j)
               if(a[i][j]!=buf[j]) diff++;               
            if(diff<=1) {
               printf("%d\n",i + 1);
               break;
            }
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
