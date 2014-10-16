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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)

const int INF = 1000000002;
const int MAXN = 22;

class ColorfulRoad {
public:
   
   int memo[MAXN][MAXN];
   string R, P;
   int go(int cur, int prev) {
      if(cur == SZ(R)-1) return 0;
      if(memo[cur][prev] != -1) return memo[cur][prev];
      int res = INF;
      for(int nxt = cur + 1; nxt < SZ(R); ++nxt) {
         if((R[cur] == 'R' && R[nxt] == 'G') || 
            (R[cur] == 'G' && R[nxt] == 'B') ||
            (R[cur] == 'B' && R[nxt] == 'R')) {
            res = min(res, go(nxt, cur) + (nxt - cur)*(nxt - cur));
         }
      }
      return memo[cur][prev] = res;
   }
   
   int getMin(string road) {
      memset(memo, -1, sizeof(memo));
      R = road;
      int res = go(0,0);
      return res >= INF ? -1: res;
   }

   int getMin2( string road ) {
      int res = 1000000002;
      string pattern = "RGB";
      for(int i = 0; i < (1 << SZ(road)); ++i) {
         int mask = i;
         mask |= (1 << 0);
         mask |= (1 << (SZ(road) - 1));
         bool ok = true;
         int cost = 0, prev = 0;
         for(int j = 0, k = 0; j < SZ(road); ++j) {
            if(mask & (1 << j)) {
               if(road[j] != pattern[k]) {
                  ok = false;
                  break;
               }
               int step = (j - prev);
               cost += step*step;
               prev = j;
               k = (k + 1) % 3;
            }
         }
         if(ok) {
            res = min(res, cost);
         }
      }
      return res >= 1000000002 ? -1: res;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
   int run_test_case(int);
   void run_test( int casenum = -1 ) {
      if ( casenum != -1 ) {
         if ( run_test_case( casenum ) == -1 )
            cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
         return;
      }
      
      int correct = 0, total = 0;
      for ( int i=0;; ++i ) {
         int x = run_test_case(i);
         if ( x == -1 ) {
            if ( i >= 100 ) break;
            continue;
         }
         correct += x;
         ++total;
      }
      
      if ( total == 0 ) {
         cerr << "No test cases run." << endl;
      } else if ( correct < total ) {
         cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
      } else {
         cerr << "All " << total << " tests passed!" << endl;
      }
   }
   
   long long get_time() {
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
      struct timeval tv;
      gettimeofday(&tv, NULL);
      return tv.tv_sec * 1000000LL + tv.tv_usec;
#else
      return 0;
#endif
   }
   int verify_case( int casenum, long long starttime, const int &expected, const int &received ) {
      cerr << "Example " << casenum << "... "; 
      if ( expected == received ) {
         cerr << "PASSED";
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         cerr << endl;
         return 1;
      } else {
         cerr << "FAILED";
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         cerr << endl;
         cerr << "    Expected: " << expected << endl; 
         cerr << "    Received: " << received << endl; 
         return 0;
      }
   }

   int run_test_case( int casenum__ ) {
      long long starttime__ = get_time();
      switch( casenum__ ) {
      case 0: {
         string road               = "RGGGB";
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
      case 1: {
         string road               = "RGBRGBRGB";
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
      case 2: {
         string road               = "RBBGGGRR";
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
      case 3: {
         string road               = "RBRRBGGGBBBBR";
         int expected__            = 50;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
      case 4: {
         string road               = "RG";
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
      case 5: {
         string road               = "RBRGBGBGGBGRGGG";
         int expected__            = 52;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }

      // custom cases

/*
      case 6: {
         string road               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
*/
/*
      case 7: {
         string road               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
*/
/*
      case 8: {
         string road               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulRoad().getMin( road ) );
      }
*/
      default:
         return -1;
      }
   }
}

// END CUT HERE

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
   if (argc > 1) {
      for (int i = 1; i < argc; ++i)
         moj_harness::run_test(atoi(argv[i]));
   }
   else {
      moj_harness::run_test();
   }
   return 0;
}
// END CUT HERE
