/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12060  C++  "Ad Hoc, average" */
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

bool ispal(char *s) {
   int lo = 0;
   int hi = strlen(s) - 1;
   while(lo < hi) {
      if(s[lo] != s[hi]) 
         return false;
      lo++;
      hi--;
   }
   return true;
}

int main(int argc, char *argv[]) {
   char buf[32];
   int k = 1;
   for(int i = 1; i <= 100000; ++i) {
      sprintf(buf,"%d",i);
      if(ispal(buf)) {
         printf("%d\n",k);
         k++;
      }
      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
