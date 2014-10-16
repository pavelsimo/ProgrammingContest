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

map<int,int> X;

int main(int argc, char *argv[]) { 
   int a, b, m, r0;
   cin >> a >> b >> m >> r0;
   for(int i = 0; true; ++i) {
      r0 = (a*r0 + b) % m;
      if(X.count(r0) > 0) {
        printf("%d\n",i - X[r0]); 
        return 0;
      } else {
         X[r0] = i;
      }
   }
   return 0;
}

