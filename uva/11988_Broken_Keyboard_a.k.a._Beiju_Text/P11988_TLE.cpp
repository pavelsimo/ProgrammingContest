/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11988  C++  "Ad Hoc, Data Structure" */
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

char buf[100020];

int main(int argc, char *argv[]) {
   int pos = 0, n;
   string res;
   while(gets(buf)) {
      res = "";
      pos = 0;
      n = strlen(buf);
      for(int i = 0; i < n; ++i) {
         char ch = buf[i];
         if(ch=='[') {
            pos = 0;
            continue;
         }
         if(ch==']') {
            pos = sz(res);
            continue;
         }
         res.insert(pos,1,ch);
         pos++;
      }
      puts(res.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

