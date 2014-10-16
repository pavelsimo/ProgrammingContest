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

int a[1002];

int main(int argc, char *argv[]) {
   int N, res = 0;
   cin >> N;
   for(int i = 0; i < N; ++i)
       cin >> a[i];
   for(int i = 0; i < N; ++i) {
      int cnt = 1;
      for(int j = i - 1; j >= 0 && a[j] <= a[j + 1]; --j) cnt++;
      for(int j = i + 1; j < N  && a[j] <= a[j - 1]; ++j) cnt++;
      res = max(res, cnt);
   }
   cout << res << endl;
   return 0;
}
