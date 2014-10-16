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

class CountingSeries {
public:
   long long countThem( long long a, long long b, long long c, long long d, long long upperBound ) {
      if(a > upperBound && c > upperBound) return 0LL;
      return 0LL;
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
         long long a               = 1LL;
         long long b               = 1LL;
         long long c               = 1LL;
         long long d               = 2LL;
         long long upperBound      = 1000LL;
         long long expected__      = 1000LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
      case 1: {
         long long a               = 3LL;
         long long b               = 3LL;
         long long c               = 1LL;
         long long d               = 2LL;
         long long upperBound      = 1000LL;
         long long expected__      = 343LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
      case 2: {
         long long a               = 40LL;
         long long b               = 77LL;
         long long c               = 40LL;
         long long d               = 100000LL;
         long long upperBound      = 40LL;
         long long expected__      = 1LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
      case 3: {
         long long a               = 452LL;
         long long b               = 24LL;
         long long c               = 4LL;
         long long d               = 5LL;
         long long upperBound      = 600LL;
         long long expected__      = 10LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
      case 4: {
         long long a               = 234LL;
         long long b               = 24LL;
         long long c               = 377LL;
         long long d               = 1LL;
         long long upperBound      = 10000LL;
         long long expected__      = 408LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }

      // custom cases

/*
      case 5: {
         long long a               = LL;
         long long b               = LL;
         long long c               = LL;
         long long d               = LL;
         long long upperBound      = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
*/
/*
      case 6: {
         long long a               = LL;
         long long b               = LL;
         long long c               = LL;
         long long d               = LL;
         long long upperBound      = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
      }
*/
/*
      case 7: {
         long long a               = LL;
         long long b               = LL;
         long long c               = LL;
         long long d               = LL;
         long long upperBound      = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, CountingSeries().countThem( a, b, c, d, upperBound ) );
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
