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

#define MOD 1000000007
int H, W;

class SmallBricks31 {
public:

   int rec(int lvl, int mask, int l, int r) {
      
      return 0;
   }
   

   int countWays( int w, int h ) {
      H = h;
      W = w;
      return 0;
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
         int w                     = 1;
         int h                     = 3;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
      case 1: {
         int w                     = 3;
         int h                     = 1;
         int expected__            = 13;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
      case 2: {
         int w                     = 3;
         int h                     = 2;
         int expected__            = 84;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
      case 3: {
         int w                     = 4;
         int h                     = 9;
         int expected__            = 132976888;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
      case 4: {
         int w                     = 5;
         int h                     = 5;
         int expected__            = 11676046;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }

      // custom cases

/*
      case 5: {
         int w                     = ;
         int h                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
*/
/*
      case 6: {
         int w                     = ;
         int h                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
      }
*/
/*
      case 7: {
         int w                     = ;
         int h                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SmallBricks31().countWays( w, h ) );
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
