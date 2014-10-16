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

int a[102];

int main(int argc, char *argv[]) { 
   int n, res = 0;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = 0; i < n; ++i) {
      int j;
      for(j = 0; j < n; ++j) {
         if(i == j) continue;
         if(a[i] % 2 == a[j] % 2) break;
      }
      if(j == n) {
         res = i + 1;
         break;
      }
   }
   cout << res << endl;
   return 0;
}

