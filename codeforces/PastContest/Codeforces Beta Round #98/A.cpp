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

int main(int argc, char *argv[]) {   
   string s;
   cin >> s;
   int cnt = 1, res = 1;
   char prev = s[0];
   for(int i = 1; i < sz(s); ++i) {
      if(s[i] == prev && cnt < 5) {
         cnt++;
      } else {
         res++;
         cnt = 1;
      }
      prev = s[i];
   }
   cout << res << endl;
   return 0;
}

