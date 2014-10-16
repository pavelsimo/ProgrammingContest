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

vector<llong> PF;
int main(int argc, char *argv[]) {
   llong q;
   cin >> q;
   for (llong d = 2LL; d*d <= q; ++d) {
      while(q % d == 0LL) {
         PF.push_back(d);
         q/=d;
      }
   }
   if(q > 1) PF.push_back(q);
   if(PF.size() <= 1) {
      cout << 1 << endl;
      cout << 0 << endl;      
   } else if(PF.size() == 2) {
      cout << 2 << endl;
   } else {
      cout << 1 << endl;
      cout << PF[0] * PF[1] << endl;
   }
   return 0;
}

