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

int main(int argc, char *argv[]) {
   string s, ans;
   cin >> s;
   ans = "";
   bool at_seen = false;
   for(int i = 0; i < sz(s); ++i) {
      if(i > 0 && i + 2 < sz(s)-1 
         && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
         ans += ".";
         i = i + 2;
      } else if(!at_seen && i > 0 && i + 1 < sz(s) - 1 && s[i] == 'a' && s[i + 1] == 't') {
         ans += "@";
         at_seen = true;
         i = i + 1;
      } else {
         ans += s[i];
      }
   }
   cout << ans << endl;
   return 0;
}

 
