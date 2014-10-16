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

bool a[100002], N;

int rec(int cur, int prev) {
   if(cur == N) return 0;
   int res = 0;
   if(!a[cur] && prev)
      res = min(res, rec(cur + 1, prev
   
   return 0;
}

int main(int argc, char *argv[]) {
   int res = 0;
   string s;
   cin >> s;
   N = sz(s);
   memset(a, false, sizeof(a));
   for(int i = 0; i < sz(s); ++i)
      a[i] = isupper(s[i]);
   res = rec(0, 1);
   return 0;
}

