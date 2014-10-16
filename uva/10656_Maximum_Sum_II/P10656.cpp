/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10656  C++  "Ad Hoc, Sub-sequences" */
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

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N, a;
   while(cin >> N) {
      if(!N) break;
      bool flag = false;
      for(int i = 0; i < N; ++i) {
         cin >> a;
         if(a == 0) continue;
         if(flag) cout << ' ';
         cout << a;
         flag = true;
      }
      if(!flag) cout << 0;
      cout << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
