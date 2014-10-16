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

int a[100002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, k, cnt = 1;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = n - 2; i >= 0; --i) {
      if(a[i + 1] == a[i]) cnt++;
      else break;
   }
   if(n - cnt == 0) cout << 0 << endl;
   else if(k > n - cnt) cout << n - cnt << endl;
   else cout << -1 << endl;
   return 0;
}

