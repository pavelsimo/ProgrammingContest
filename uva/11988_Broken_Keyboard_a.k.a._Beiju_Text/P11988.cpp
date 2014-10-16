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

typedef vector<string> VS;
char buf[100020];
VS a;

int main(int argc, char *argv[]) {
   int n;
   string res;
   while(gets(buf)) {
      a.clear();
      a.push_back("");
      res = "";
      n = strlen(buf);
      for(int i = 0, j = 0; i < n; ++i) {
         char ch = buf[i];
         if(ch=='[') {
            a.push_back("");
            j = max(0,sz(a)-1);
            continue;
         }
         if(ch==']') {
            j = 0;
            continue;
         }
         a[j]+=ch;
      }
      for(int i = sz(a)-1; i >= 0; --i)
         printf("%s",a[i].c_str());
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

