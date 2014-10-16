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

int a[402];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, k;
   cin >> n >> k;
   for(int i = 1; i <= 2*n+1; ++i) cin >> a[i];
   a[0] = -200;
   a[2*n+2] = 200;
   for(int i = 1; i <= 2*n+1; ++i) {
      if(k > 0 && a[i-1] < a[i] - 1 && a[i] - 1 > a[i+1]) {
         a[i]--;
         k--;
      }      
   }
   for(int i = 1; i <= 2*n+1; ++i)
      cout << a[i] << ' ';
   cout << endl;
   return 0;
}

