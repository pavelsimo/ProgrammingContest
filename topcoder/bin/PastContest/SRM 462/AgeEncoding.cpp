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
#define pb push_back


class AgeEncoding {
public:

   double decode(string candles, double base) {
      double res = 0.0;
      for(int i = 0; i < sz(candles); ++i) {
         res*=base;
         res+=(candles[i]-'0');
      }
      return res;
   }

   double getRadix( int age, string candles ) {
      
      while (sz(candles) > 0 && candles [0] == '0')
         candles = candles.substr(1);
      if (sz(candles)== 0) 
         return -1;
      if (candles.length () == 1)
         return age == 1 ? -2 : -1; 
      if (age == 1 && sz(candles) > 1 && candles[sz(candles)- 1]=='1')
         return -1;

      double res = 0.0;
      double lo = 0.0;
      double hi = 500.0;
      for(int i = 0; i < 100; ++i) {
         double mid = lo + (hi-lo)/2.0;
         if(decode(candles,mid) > age)
            hi = mid;
         else 
            lo = mid;
      }
      res = lo;
      return res;
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
         int age                   = 10;
         string candlesLine        = "00010";
         double expected__         = 10.0;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 1: {
         int age                   = 21;
         string candlesLine        = "10101";
         double expected__         = 2.0;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 2: {
         int age                   = 6;
         string candlesLine        = "10100";
         double expected__         = 1.414213562373095;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 3: {
         int age                   = 21;
         string candlesLine        = "10111111110111101111111100111111110111111111111100";
         double expected__         = 0.9685012944510603;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 4: {
         int age                   = 16;
         string candlesLine        = "1";
         double expected__         = -1.0;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 5: {
         int age                   = 1;
         string candlesLine        = "1";
         double expected__         = -2.0;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
      case 6: {
         int age                   = 1;
         string candlesLine        = "001000";
         double expected__         = 1.0;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }

      // custom cases

/*
      case 7: {
         int age                   = ;
         string candlesLine        = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
*/
/*
      case 8: {
         int age                   = ;
         string candlesLine        = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
      }
*/
/*
      case 9: {
         int age                   = ;
         string candlesLine        = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, AgeEncoding().getRadix( age, candlesLine ) );
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
