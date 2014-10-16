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


class ThreeTeleports {
public:
   int shortestDistance( int xMe, int yMe, int xHome, int yHome, vector <string> teleports ) {

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
         int xMe                   = 3;
         int yMe                   = 3;
         int xHome                 = 4;
         int yHome                 = 5;
         string teleports[]        = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
      case 1: {
         int xMe                   = 0;
         int yMe                   = 0;
         int xHome                 = 20;
         int yHome                 = 20;
         string teleports[]        = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"};
         int expected__            = 14;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
      case 2: {
         int xMe                   = 0;
         int yMe                   = 0;
         int xHome                 = 20;
         int yHome                 = 20;
         string teleports[]        = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"};
         int expected__            = 14;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
      case 3: {
         int xMe                   = 10;
         int yMe                   = 10;
         int xHome                 = 10000;
         int yHome                 = 20000;
         string teleports[]        = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"};
         int expected__            = 30;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
      case 4: {
         int xMe                   = 3;
         int yMe                   = 7;
         int xHome                 = 10000;
         int yHome                 = 30000;
         string teleports[]        = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"};
         int expected__            = 117;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
      case 5: {
         int xMe                   = 0;
         int yMe                   = 0;
         int xHome                 = 1000000000;
         int yHome                 = 1000000000;
         string teleports[]        = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"};
         int expected__            = 36;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int xMe                   = ;
         int yMe                   = ;
         int xHome                 = ;
         int yHome                 = ;
         string teleports[]        = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         int xMe                   = ;
         int yMe                   = ;
         int xHome                 = ;
         int yHome                 = ;
         string teleports[]        = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         int xMe                   = ;
         int yMe                   = ;
         int xHome                 = ;
         int yHome                 = ;
         string teleports[]        = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ThreeTeleports().shortestDistance( xMe, yMe, xHome, yHome, vector <string>( teleports, teleports + ( sizeof teleports / sizeof(string) ) ) ) );
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
