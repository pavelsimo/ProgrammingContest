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

int memo[4002][4002], X, Y, lo, hi;

class PatrolRoute {
public:
   
   int countRoutes( int x, int y, int minT, int maxT ) {
      
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
         int X                     = 3;
         int Y                     = 3;
         int minT                  = 1;
         int maxT                  = 20000;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
      case 1: {
         int X                     = 3;
         int Y                     = 3;
         int minT                  = 4;
         int maxT                  = 7;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
      case 2: {
         int X                     = 4;
         int Y                     = 6;
         int minT                  = 9;
         int maxT                  = 12;
         int expected__            = 264;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
      case 3: {
         int X                     = 7;
         int Y                     = 5;
         int minT                  = 13;
         int maxT                  = 18;
         int expected__            = 1212;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
      case 4: {
         int X                     = 4000;
         int Y                     = 4000;
         int minT                  = 4000;
         int maxT                  = 14000;
         int expected__            = 859690013;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }

      // custom cases

/*
      case 5: {
         int X                     = ;
         int Y                     = ;
         int minT                  = ;
         int maxT                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
*/
/*
      case 6: {
         int X                     = ;
         int Y                     = ;
         int minT                  = ;
         int maxT                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
      }
*/
/*
      case 7: {
         int X                     = ;
         int Y                     = ;
         int minT                  = ;
         int maxT                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PatrolRoute().countRoutes( X, Y, minT, maxT ) );
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
