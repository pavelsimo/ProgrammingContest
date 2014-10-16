/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10922  C++  "Number Theory, Divisibility" */
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

int main(int argc, char *argv[]) {
   int sum, d;
   string s;
   while(cin >> s) {
      if(s[0]=='0') break;
      sum = 0; d = 1;
      for(int i = 0; i < sz(s); ++i) sum+=(s[i]-'0');
      if(sum % 9 == 0) {
         while(sum > 9) {
            int t = 0;
            int x = sum;
            while(x > 0) {
               t+=(x%10);
               x/=10;
            }
            sum = t;
            d++;
         }
         printf("%s is a multiple of 9 and has 9-degree %d.\n",s.c_str(),d);
      } else {
         printf("%s is not a multiple of 9.\n",s.c_str());
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

