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
   int m_base = 0, xa = 0, xb = 0, res = 0;
   string a, b;
   cin >> a >> b;
   for(int i = 0; i < sz(a); ++i) m_base = max(m_base, a[i] - '0');
   for(int i = 0; i < sz(b); ++i) m_base = max(m_base, b[i] - '0');
   m_base++;
   for(int i = 0; i < sz(a); ++i)
      xa = xa * m_base + (a[i] - '0');
   for(int i = 0; i < sz(b); ++i)
      xb = xb * m_base + (b[i] - '0');
   int x = xa + xb;
   while(x > 0) {
      res++;
      x/=m_base;
   }
   cout << res << endl;
   return 0;
}

