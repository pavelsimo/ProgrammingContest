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

int getmask(int n) {
   int t = 0, res = 0;
   while(n > 0) {
      if(n%10 == 4 || n%10 == 7)
         t = t*10 + (n%10);
      n/=10;
   }
   while(t > 0) {
      res = res*10 + t%10;
      t/=10;
   }
   return res;
}

int main(int argc, char *argv[]) {
   int a, b, c;
   cin >> a >> b;
   if(b > a) {
      printf("%d\n",b);
   } else {
      for(c = a + 1; true; ++c)
         if(getmask(c) == b) break;
      printf("%d\n",c);
   }
   return 0;
}

