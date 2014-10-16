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

#define BITCOUNT(mask) ( __builtin_popcountll((mask)) )

typedef long long llong;

int N;
llong MOD = 1000000007;
string S[202];
llong lo[26], uniq[26], hi[26];
llong freq[26];

llong solve() {
   memset(freq, 0, sizeof(freq));
   memset(uniq, false, sizeof(uniq));
   memset(lo, 0, sizeof(lo));
   memset(hi, 0, sizeof(hi));
   for(int i = 0; i < N; ++i) {
      for(int j = 1; j < sz(S[i]); ++j) {
         if(S[i-1] != S[i] && S[i] != S[i+1]) {
            return 0LL;
         }
      }
   }
   for(int i = 0; i < N; ++i) {
      set<char> X;
      for(int j = 0; j < sz(S[i]); ++j)
         X.insert(S[i][j]);
      if(sz(X) == 1) {
         uniq[*X.begin() - 'a']++;
      } else {
         lo[S[i][0]-'a']++;
         hi[S[i][0]-'a']++;
      }
   }   
   return 0LL;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      for(int i = 0; i < N; ++i) {
         cin >> S[i];
      }

      cout << "Case #" << tc << ": " << 0 << endl;
   }
   return 0;
}
