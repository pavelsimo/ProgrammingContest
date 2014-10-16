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

typedef long long llong;

struct Group {
   int st, et, ind; 
   Group(int _st = 0, int _et = 0, int _ind = 0) :
      st(_st), et(_et), ind(_ind) {}
   bool operator<(const Group &T) const {
      if(et != T.et) return et < T.et;
      return st < T.st;
   }
};

Group a[5002];
vector<int> ans;

int main(int argc, char *argv[]) {
   int n; 
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> a[i].st >> a[i].et;
      a[i].ind = i + 1;
   }
   sort(a, a + n);
   for(int i = 0; i < n; ++i) {
      int prev = -1;
      bool ok = true;
      for(int j = 0; j < n; ++j) {
         if(i == j) continue;
         if(prev > a[j].st) {
            ok = false;
            break;
         }
         prev = a[j].et;
      }
      if(ok) ans.push_back(a[i].ind);
   }
   sort(all(ans));
   cout << sz(ans) << endl;
   for(int i = 0; i < sz(ans); ++i)
      cout << ans[i] << ' ';
   if(sz(ans)) cout << endl; 
   return 0;
}

