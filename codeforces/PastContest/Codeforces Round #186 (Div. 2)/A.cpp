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

int go1(int n) {
   string res = tostr(n);
   return atoi(res.substr(0, sz(res) - 1).c_str());
}

int go2(int n) {
   string res = tostr(n);
   string t = res.substr(0, sz(res) - 2);
   t += res[sz(res)-1];
   return atoi(t.c_str());
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, res; 
   cin >> n;
   res = n;
   res = max(res, go1(n));
   res = max(res, go2(n));
   cout << res << endl;
   return 0;
}
