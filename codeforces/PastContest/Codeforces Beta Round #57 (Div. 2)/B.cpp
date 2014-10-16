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

string normalize(string s) {
   string res = "";
   for(int i = 0; i < sz(s); ++i)
      if(isalpha(s[i]))
         res += tolower(s[i]);
   return res;
}

int main(int argc, char *argv[]) {
   int N, ind[] = {0, 1, 2};
   string s[3], ans;
   cin >> s[0] >> s[1] >> s[2];
   s[0] = normalize(s[0]);
   s[1] = normalize(s[1]);
   s[2] = normalize(s[2]);
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> ans;
      ans = normalize(ans);
      bool ac = false;
      do {
         string test = s[ind[0]] + s[ind[1]] + s[ind[2]];
         if(ans == test) {
            ac = true;
            break;
         }
      } while(next_permutation(ind, ind + 3));
      ind[0] = 0; ind[1] = 1; ind[2] = 2;
      cout << (ac ? "ACC": "WA") << endl;
   }
   return 0;
}
