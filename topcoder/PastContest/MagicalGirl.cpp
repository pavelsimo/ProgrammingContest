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


class MagicalGirl {
public:
   double maxExpectation( int M, vector <int> day, vector <int> win, vector <int> gain ) {

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
         int M                     = 2;
         int day[]                 = {1};
         int win[]                 = {75};
         int gain[]                = {1};
         double expected__         = 2.5;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 1: {
         int M                     = 10;
         int day[]                 = {5,5,5,5};
         int win[]                 = {100,100,100,100};
         int gain[]                = {1,1,1,1};
         double expected__         = 14.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 2: {
         int M                     = 10;
         int day[]                 = {5,5,5,5,5};
         int win[]                 = {40,80,60,20,0};
         int gain[]                = {10,10,10,10,10};
         double expected__         = 13.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 3: {
         int M                     = 2;
         int day[]                 = {2};
         int win[]                 = {100};
         int gain[]                = {2};
         double expected__         = 2.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 4: {
         int M                     = 20;
         int day[]                 = {2,13,8,7,9,4,6,21};
         int win[]                 = {18,83,75,23,45,23,10,98};
         int gain[]                = {10,9,8,10,7,16,13,20};
         double expected__         = 35.908;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 5: {
         int M                     = 11;
         int day[]                 = {10,20,30,40,50,60,70,80,90};
         int win[]                 = {100,100,100,100,100,100,100,100,100};
         int gain[]                = {10,10,10,10,10,10,10,10,10};
         double expected__         = 101.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
      case 6: {
         int M                     = 100000;
         int day[]                 = {1000000};
         int win[]                 = {100};
         int gain[]                = {100000};
         double expected__         = 100000.0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 7: {
         int M                     = ;
         int day[]                 = ;
         int win[]                 = ;
         int gain[]                = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int M                     = ;
         int day[]                 = ;
         int win[]                 = ;
         int gain[]                = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
      }
*/
/*
      case 9: {
         int M                     = ;
         int day[]                 = ;
         int win[]                 = ;
         int gain[]                = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirl().maxExpectation( M, vector <int>( day, day + ( sizeof day / sizeof(int) ) ), vector <int>( win, win + ( sizeof win / sizeof(int) ) ), vector <int>( gain, gain + ( sizeof gain / sizeof(int) ) ) ) );
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
