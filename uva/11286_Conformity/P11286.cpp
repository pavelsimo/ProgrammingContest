/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11286  C++  "Ad Hoc, Frequency" */
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

map<string, int> freq;
string A[10002][5];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N, ma, res;
   while(cin >> N) {
      if(!N) break;
      freq.clear();
      ma = 0;
      for(int i = 0; i < N; ++i) {
         cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3] >> A[i][4];
         sort(A[i], A[i] + 5);
         ma = max(ma, ++freq[A[i][0] + A[i][1] + A[i][2] + A[i][3] + A[i][4]]);
      }
      res = 0;
      foreach(it, freq) {
         if(it->second == ma) 
            res += it->second;
      }
      cout << res << '\n';
   }

   return 0;
}
/* @END_OF_SOURCE_CODE */
