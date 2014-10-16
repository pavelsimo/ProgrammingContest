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

llong points[55], prizes[6], freq[6];

int main(int argc, char *argv[]) {
   int n;
   memset(freq, 0, sizeof(freq));
   llong pts = 0LL;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> points[i];
   for(int i = 0; i < 5; ++i)
      cin >> prizes[i];
   for(int i = 0; i < n; ++i) {
      pts += points[i];
      for(int j = 4; j >= 0; --j) {
         if(pts >= prizes[j]) {
            llong X = pts/prizes[j];
            pts-=prizes[j] * X;
            freq[j]+=X;
         }
      }
   }
   for(int i = 0; i < 5; ++i)
      cout << freq[i] << ' ';
   cout << endl;
   cout << pts << endl;
   return 0;
}

