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

string tobase3(int n) {
   string res = "";
   while(n > 0) {
      res = tostr((char)('0'+(n % 3))) + res;
      n/=3;
   }
   return sz(res) == 0 ? "0": res;
}

int main(int argc, char *argv[]) {
   int p1, p2, n;
   cin >> p1 >> p2;
   string a = tobase3(p1), b = "", c = tobase3(p2);
   n = max(sz(a),sz(c));
   a = string(n-sz(a),'0') + a;
   c = string(n-sz(c),'0') + c;
   int res = 0;
   for(int i = 0; i < n; ++i) {
      int a1 = a[i]-'0';
      int c1 = c[i]-'0';
      if(a1==c1) res*=3;
      else if((a1+1)%3 == c1) res = res*3 + 1;
      else res = res*3 + 2;
   }
   cout << res << endl;
   return 0;
}

