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

// 1c, 2c, 5c, 10c, 20c, 50c, 1 Euro, 2 Euro, 5 Euro, 10 Euro, 20 Euro, 50 Euro, and 100 Euro
int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, s, c;
   cin >> TC;
   while(TC--) {
      cin >> s >> c;
      vector<int> A(13);
      A[6]+=s;
      A[0]+=c;
      for(int i = 0; i < sz(A); ++i) {
         if(i > 0) cout << ' ';
         cout << A[i];
      }
      cout << endl;
   }
   return 0;
}
