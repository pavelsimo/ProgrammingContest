/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ DISUBSTR C++ "Suffix Array, Suffix Tries" */
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

typedef long long llong;

vector<int> LCP;
vector<string> S;

int lcp(int i, int j) {
   int N = min(sz(S[i]), sz(S[j]));
   for(int k = 0; k < N; ++k)
      if(S[i][k] != S[j][k]) return k;
   return N;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, res;
   string s;
   cin >> TC;
   while(TC-- > 0) {
      cin >> s;
      S.clear(); LCP.clear();
      for(int i = 0; i < sz(s); ++i) {
         S.push_back(s.substr(i));
         LCP.push_back(0);
      }
      sort(all(S));
      for(int i = 1; i < sz(S); ++i)
         LCP[i] = lcp(i - 1, i);
      res = 0;
      for(int i = 0; i < sz(S); ++i)
         res += sz(S[i]) - LCP[i];
      cout << res << endl;
   }
   return 0;
}
