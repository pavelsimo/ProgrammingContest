/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11687  C++  "Ad Hoc, Math" */
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

char buf[1000010];

int main(int argc, char *argv[]) {
   int x0, x1, res;
   while(gets(buf)) {
      if(buf[0]=='E') break;
      res = 1;
      x0 = strlen(buf);
      if(x0 == 1 && buf[0]=='1') {
         printf("%d\n",res);
      } else {
         while(true) {
            res++;
            sprintf(buf,"%d",x0);
            x1 = strlen(buf);
            if(x0 == x1) break;
            x0 = x1;
         }  
         printf("%d\n",res);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
