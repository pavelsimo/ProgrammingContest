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

const double EPS = 1e-5;
int vp, vd, t, f, c;

bool check(int bijous) {
   double tp, td, cp, cd;
   int tx = t;
   cp = cd = c;
   for(int i = 1, j = 1; i <= c; ++i, ++j) {
      tp = 1.0*i/vp;
      td = 1.0*j/vd + tx;
      printf("%.2f %.2f\n",tp,td);
      if(td*vd > tp*vp) {
         if(bijous > 0) {
            j = 0;
            tx = f;
            bijous--;
         } else {
            return false;
         }
      }
   }
   return true;
}

int main(int argc, char *argv[]) {
   int res;
   cin >> vp >> vd >> t >> f >> c;
   for(res = 0; true; ++res) {
      if(check(res))
         break;
   }
   cout << res << endl;
   return 0;
}

