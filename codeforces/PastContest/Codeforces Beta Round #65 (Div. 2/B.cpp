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
   int n, k, t;
   cin >> n >> k >> t;
   int x = n * k * t;
   for(int i = 0; i < n; ++i) {
      if(x >= k * 100) {
         cout << k << ' ';
         x-=(k * 100);
      } else {
         cout << x/100 << ' ';
         x = 0;
      }
   }
   cout << endl;
   return 0;
}

 
