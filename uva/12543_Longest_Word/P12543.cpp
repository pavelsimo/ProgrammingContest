/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  Longest Word  C++  "Ad Hoc" */
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

template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


typedef unsigned long long ullong;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s, res = "";
   while(cin >> s) {
      if(s == "E-N-D") break;
      string word = "";
      for(int i = 0; i < sz(s); ++i) {
         if(isalpha(s[i]) || s[i] == '-')
            word += s[i];
      }
      if(word.size() > res.size())
         res = word;
   }
   for(int i = 0; i < sz(res); ++i) 
      res[i] = tolower(res[i]);
   cout << res << endl;
   return 0;
}
/* @END_OF_SOURCE_CODE */

