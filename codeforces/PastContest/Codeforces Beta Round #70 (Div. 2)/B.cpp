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

string colors = "ROYGBIV";

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, lo, hi, t, k;   
   cin >> n;
   string res(" ", n);
   lo = t = k = 0;
   hi = n - 1;
   while(lo <= hi) {
      k = (k + 1) % sz(colors);
      if(t) res[lo++] = colors[k];
      else res[hi--] = colors[k];
      t^=1;
   }
   cout << res << endl;
   return 0;
}

