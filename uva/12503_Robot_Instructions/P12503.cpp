/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12503  C++  "Ad Hoc, Simulation" */
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

int H[102];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string cmd, t;
   int TC, N, p, ind;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N;
      p = 0;
      for(int i = 0; i < N; ++i) {
         cin >> cmd;
         if(cmd[0] == 'L') H[i] = -1;
         else if(cmd[0] == 'R') H[i] = 1;
         else {
            cin >> t >> ind;
            --ind;
            H[i] = H[ind];
         }
         p += H[i];
      }
      cout << p << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

