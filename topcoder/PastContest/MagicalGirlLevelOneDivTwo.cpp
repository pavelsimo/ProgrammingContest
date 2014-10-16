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


class MagicalGirlLevelOneDivTwo {
public:
   double theMinDistance( int d, int x, int y ) {
      x = abs(x);
      y = abs(y);
      int dx = x - d;
      int dy = y - d;
      if(dx < 0) dx = 0;
      if(dy < 0) dy = 0;
      return sqrt(dx*dx + dy*dy);
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
   
   static const double MAX_DOUBLE_ERROR = 1e-9;
   static bool topcoder_fequ( double expected, double result ) {
      if ( isnan( expected ) )
         return isnan( result );
      if ( isinf( expected ) )
         return expected > 0 ? result > 0 && isinf( result ) :
                               result < 0 && isinf( result );
      if ( isnan( result ) || isinf( result ) )
         return false;
      if ( fabs( result - expected ) < MAX_DOUBLE_ERROR )
         return true;
      return result > min(expected * (1.0 - MAX_DOUBLE_ERROR),
                          expected * (1.0 + MAX_DOUBLE_ERROR))
          && result < max(expected * (1.0 - MAX_DOUBLE_ERROR),
                          expected * (1.0 + MAX_DOUBLE_ERROR));
   }
   double moj_relative_error( double expected, double result ) {
      if ( isnan( expected ) || isinf( expected ) ||
           isnan( result ) || isinf( result ) || expected == 0 )
         return 0;
      return fabs( result-expected ) / fabs( expected );
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
   int verify_case( int casenum, long long starttime, const double &expected, const double &received ) {
      cerr << "Example " << casenum << "... "; 
      cerr.precision(9); 
      if ( topcoder_fequ( expected, received ) ) {
         cerr << "PASSED"; 
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         double rerr = moj_relative_error( expected, received ); 
         if ( rerr > 0 ) cerr << "  (rerr " << rerr << ")";
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
         int d                     = 5;
         int x                     = 10;
         int y                     = 10;
         double expected__         = 7.0710678118654755;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
      case 1: {
         int d                     = 5;
         int x                     = 10;
         int y                     = 3;
         double expected__         = 5.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
      case 2: {
         int d                     = 5;
         int x                     = -8;
         int y                     = -6;
         double expected__         = 3.1622776601683795;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
      case 3: {
         int d                     = 5;
         int x                     = 3;
         int y                     = 2;
         double expected__         = 0.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
      case 4: {
         int d                     = 24;
         int x                     = 24;
         int y                     = -24;
         double expected__         = 0.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
      case 5: {
         int d                     = 345;
         int x                     = -471;
         int y                     = 333;
         double expected__         = 126.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }

      // custom cases

/*
      case 6: {
         int d                     = ;
         int x                     = ;
         int y                     = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
*/
/*
      case 7: {
         int d                     = ;
         int x                     = ;
         int y                     = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
      }
*/
/*
      case 8: {
         int d                     = ;
         int x                     = ;
         int y                     = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelOneDivTwo().theMinDistance( d, x, y ) );
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
