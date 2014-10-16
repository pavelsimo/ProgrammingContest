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
   int TC;
   string S;
   cin >> TC;
   while(TC-- > 0) {
      cin >> S;
      int cnt = 1, jump = 1, res = 0;
      for(int i = 0; i < sz(S); ++i) {
         if(S[i] == '.') {
            cnt++;
         } else {
            if(cnt > jump) {
               res++;
               jump = cnt;
            }
            cnt = 1;
         }
      }
      cout << res << endl;
   }
   return 0;
}

