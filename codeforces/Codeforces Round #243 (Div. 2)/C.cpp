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

const int MAXN = 256;
int a[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k, s = 0;
   bool neg = false;
   
   cin >> n >> k;
   for(int i = 0; i < n; ++i) {
      cin >> a[i]; 
      if(a[i] < 0) neg = true;
      s += a[i];
   }
   
   if(!neg) {
      cout << s << endl;
      return 0;
   }
   
   int ans = -1000002;
   for(int l = 0; l < n; ++l) {
      for(int r = l; r < n; ++r) {
         vector<int> mid, rem;
         for(int i = 0; i < l; ++i) rem.push_back(a[i]);
         for(int i = l; i <= r; ++i) mid.push_back(a[i]);
         for(int i = r + 1; i < n; ++i) rem.push_back(a[i]);
         
         sort(rem.rbegin(), rem.rend());
         sort(mid.begin(), mid.end());
         
         int sum = 0, swap_cnt = 0;
         for(int i = 0, j = 0; i < sz(mid); ++i) {
            int cur = mid[i];
            if(j < sz(rem) && swap_cnt < k && rem[j] > cur) {
               cur = rem[j];
               ++j;
               swap_cnt++;
            }
            sum += cur;
         }
         ans = max(ans, sum);
      }
   }
   cout << ans << endl;
   
   return 0;
}
