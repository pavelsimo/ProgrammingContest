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

bool seen[10002];
int a[10002], b[10002];

int main(int argc, char *argv[]) {
   memset(seen, false, sizeof(seen));   
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for(int i = 0; i < n; ++i) {
      int x = a[i];
      int sum = 0;
      while(x > 0) {
         sum += (x % 10);
         x/=10;
      }
      b[i] = sum;
   }
   int res = 0;
   for(int i = 0; i < n; ++i) {
      if(seen[i]) continue;
      for(int j = i + 1; j < n; ++j) {
         if(seen[j]) continue;
         if((b[i] + b[j]) % 3 == 0) {
            res++;
            seen[i] = seen[j] = true;
            break;
         }
      }
   }
   cout << res << endl;
   return 0;
}

 
