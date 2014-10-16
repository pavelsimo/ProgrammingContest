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

double Pr[199999];
int A, B;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int TC;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> A >> B;
      for(int i = 1; i <= A; ++i)
         cin >> Pr[i];
      double res = B + 2;
      double p = 1;
      Pr[0] = 1;
      for(int i = 0; i <= A; ++i) {
         p = p * Pr[i];
         double eval = (B-i + A-i + 1 + B+1)*(1 - p) + (B-i + A-i + 1)*p;
         res = min(res, eval);   
      }
      printf("Case #%d: %.7lf\n", tc, res);
   }
   return 0;
}

