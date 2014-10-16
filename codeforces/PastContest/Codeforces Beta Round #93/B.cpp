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

int freq[256];
int main(int argc, char *argv[]) {
   memset(freq,0,sizeof(freq));
   int n, a, res = 0;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> a;
      freq[a]++;
   }
   for(int i = 1; i <= 110; ++i)
      res+=freq[i]/2;
   cout << res/2 << endl;
   return 0;
}

