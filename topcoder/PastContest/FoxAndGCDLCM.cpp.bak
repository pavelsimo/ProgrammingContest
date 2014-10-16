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
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;
const llong INF = (llong) 1e18;

class FoxAndGCDLCM {
public:
   
   template<typename INT>
   INT gcd(INT a, INT b) {
      if (a < 0) a = -a;
      if (b < 0) b = -b;
      if (a < b) swap(a, b);
      while (b > 0) {
         INT t = b;
         b = a % b;
         a = t;
      }
      return a > 0 ? a : 1;
   }
   
   llong calc(llong G, llong L) {
      llong res = INF;
      llong N = L/G;
      for(llong i = 1; i * i <= N; ++i) {
         if(N % i == 0) {
            llong A = i;
            llong B = N/i;
            if(gcd(A,B) == 1)
               res = min(res, (A + B)*G);            
         }
      }
      return res;
   }

   long long get( long long G, long long L ) {
      if(L % G != 0) return -1;
      llong res = calc(G, L);
      return res == INF ? -1: res;
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
   int verify_case( int casenum, long long starttime, const long long &expected, const long long &received ) {
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
         long long G               = 2LL;
         long long L               = 20LL;
         long long expected__      = 14LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }
      case 1: {
         long long G               = 5LL;
         long long L               = 8LL;
         long long expected__      = -1LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }
      case 2: {
         long long G               = 1000LL;
         long long L               = 100LL;
         long long expected__      = -1LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }
      case 3: {
         long long G               = 100LL;
         long long L               = 1000LL;
         long long expected__      = 700LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }
      case 4: {
         long long G               = 10LL;
         long long L               = 950863963000LL;
         long long expected__      = 6298430LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }

      // custom cases


      case 5: {
         long long G               = 2LL;
         long long L               = 6LL;
         long long expected__      = 8LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }

/*
      case 6: {
         long long G               = LL;
         long long L               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
      }
*/
/*
      case 7: {
         long long G               = LL;
         long long L               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, FoxAndGCDLCM().get( G, L ) );
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
