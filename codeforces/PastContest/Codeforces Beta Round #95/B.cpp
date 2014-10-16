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
map<int,llong> freq;

int main(int argc, char *argv[]) {
   int n, x;
   llong res;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> x;
      freq[x]++;
   }
   res = 0;
   for(int i = -10; i <= -1; ++i)
      res+=freq[i]*freq[-i];
   res+=(freq[0]*(freq[0]-1))/2LL;
   cout << res << endl;
   return 0;
}

