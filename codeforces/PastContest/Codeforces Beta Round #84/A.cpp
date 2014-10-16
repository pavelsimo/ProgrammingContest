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

bool f(llong N) {
   llong x = N;
   int cnt = 0;
   while(x > 0) {
      if(x%10 == 4LL || x%10 == 7LL) 
         cnt++;
      x/=10LL;
   }
   return cnt == 4 || cnt == 7;
}

int main(int argc, char *argv[]) {
   llong N;
   cin >> N;
   if(f(N)) puts("YES");
   else puts("NO");
   return 0;
}

