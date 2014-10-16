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

vector<llong> X, pow9, sum9;

llong solve(llong n) {
   int pos = lower_bound(all(X), n) - X.begin();
   DEBUG(n);
   DEBUG(pos);
   return 0LL;
}

int main(int argc, char *argv[]) {
   llong lo, hi;
   cin >> lo >> hi;
   for(llong i = 9, j = 9, k = 0; true; 
      i = i * 10 + 9, j*=9LL, ++k) {
      X.push_back(i);
      pow9.push_back(j);
      sum9.push_back(j);
      if(k > 0) sum9[k] += sum9[k - 1];
      DEBUG(j);
      if(i > hi) break;
   }
   DEBUG(solve(hi));
   
   return 0;
}

