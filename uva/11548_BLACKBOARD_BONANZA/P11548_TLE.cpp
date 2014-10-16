/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11548  C++  "String, Substrings" */
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

const int MAXN = 72;

set<string> S[MAXN];
vector<string> X;
string dict[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, n, res = 0;
   cin >> TC;
   while(TC-- > 0) {
      cin >> n;
      X.clear();
      for(int i = 0; i < n; ++i) {
         S[i].clear();
         cin >> dict[i];
         for(int j = 1; j <= sz(dict[i]); ++j) {
            for(int k = 0; k + j <= sz(dict[i]); ++k) {
               string s = dict[i].substr(k, j);
               S[i].insert(s);        
            }
         }
      }
      for(int i = 0; i < n; ++i) {
         foreach(it, S[i]) {
            string s = *it;
            X.push_back(s);
         }
      }
      sort(all(X));
      res = 0;
      for(int i = 0; i < sz(X) - 1; ++i) {
         if(X[i] == X[i + 1])
            res = max(res, sz(X[i]));
      }
      cout << res << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

