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

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, s, x;
   vector<int> a;
   cin >> n >> s;
   for(int i = 0; i < n; ++i) {
      cin >> x;
      a.push_back(x);
   }
   sort(a.begin(), a.end());
   int sum = 0;
   for(int i = 0; i < n - 1; ++i) {
      sum += a[i];
   }
   if(sum > s) cout << "NO" << endl;
   else cout << "YES" << endl;
   return 0;
}
