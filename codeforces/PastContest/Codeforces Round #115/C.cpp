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

llong p[102];
int t, n;
vector<pair<llong, llong> >  X;

int main(int argc, char *argv[]) {
   cin >> n;
   llong k, c;
   for(int i = 0; i < n; ++i) {
      cin >> k >> c;
      X.push_back(make_pair(c, k));
   }
   sort(all(X));
   cin >> t;
   for(int i = 0; i < t; ++i)
      cin >> p[i];
   llong res = 0LL;
   llong f = 1;
   for(int i = 0; i < sz(X); ++i) {
      int j = 0;
      
      while(X[i].second > 0 && j < t) {
         if(X[i].second >= p[j]) {
            llong t = (j == t - 1) ? X[i].second : p[j]; 
            res += f * X[i].first * p[j];
            ++f;
         } else {
            res += f * X[i].first * X[i].second;
            break;
         }
         X[i].second -= p[j];
         ++j;
      }
   }
   cout << res << endl;
   return 0;
}

