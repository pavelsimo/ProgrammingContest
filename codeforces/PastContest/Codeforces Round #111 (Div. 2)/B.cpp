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

bool is_unlucky(string &a, string &b) {
   bool c1, c2;
   c1=c2=true;
   for(int i = 0; i < sz(a); ++i) {
      if(a[i] >= b[i]) c2 = false;
      if(a[i] <= b[i]) c1 = false;
   }
   return c1||c2;
}

int main(int argc, char *argv[]) {
   int N;
   string s, a, b;
   cin >> N >> s;
   for(int i = 0; i < N; ++i) {
      a+=s[i];
      b+=s[N+i];
   }
   sort(all(a));
   sort(all(b));
   if(is_unlucky(a, b)) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}

