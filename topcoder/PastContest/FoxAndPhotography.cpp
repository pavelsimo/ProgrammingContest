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


class FoxAndPhotography {
public:
   int getMinimumSwaps( vector <int> heightsFront, vector <int> heightsBack ) {

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
         int heightsFront[]        = {140, 150};
         int heightsBack[]         = {160, 150};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
      case 1: {
         int heightsFront[]        = {140, 140, 140, 140};
         int heightsBack[]         = {190, 190, 190, 190};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
      case 2: {
         int heightsFront[]        = {170, 170, 170};
         int heightsBack[]         = {160, 170, 180};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
      case 3: {
         int heightsFront[]        = {140, 141, 142, 143};
         int heightsBack[]         = {144, 143, 142, 141};
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
      case 4: {
         int heightsFront[]        = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170} ;
         int heightsBack[]         = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150};
         int expected__            = 15;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int heightsFront[]        = ;
         int heightsBack[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int heightsFront[]        = ;
         int heightsBack[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int heightsFront[]        = ;
         int heightsBack[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndPhotography().getMinimumSwaps( vector <int>( heightsFront, heightsFront + ( sizeof heightsFront / sizeof(int) ) ), vector <int>( heightsBack, heightsBack + ( sizeof heightsBack / sizeof(int) ) ) ) );
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
