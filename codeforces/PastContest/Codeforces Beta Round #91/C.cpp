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
vector<llong> lucky;
queue<llong> Q;

llong count(llong n) {
   llong res = 0LL;
   llong prev = 0;
   for(int i = 0; i < sz(lucky); ++i) {
      if(n <= lucky[i]) {
         res+=(n-prev)*lucky[i];
         break;
      } else {
         res+=(lucky[i]-prev)*lucky[i];
      }
      prev = lucky[i];
   }
   return res;
}

int main(int argc, char *argv[]) {
   Q.push(4); Q.push(7);
   while(!Q.empty()) {
      llong cur = Q.front(); Q.pop();
      if(cur > 10000000000LL) continue;
      lucky.push_back(cur);
      Q.push(cur*10LL + 4LL);
      Q.push(cur*10LL + 7LL);
   }
   llong lo, hi;
   cin >> lo >> hi;
   cout << count(hi) - count(lo-1) << endl;
   return 0;
}

