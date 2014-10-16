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


class EllysLights {
public:
   int getMinimum( string initial, vector <string> switches ) {

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
         string initial            = "YNYNNN";
         string switches[]         = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
      case 1: {
         string initial            = "YNYNYN";
         string switches[]         = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
      case 2: {
         string initial            = "YYN";
         string switches[]         = {"YNY", "NYN"};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
      case 3: {
         string initial            = "NNYNYNYYYNNYYYYN";
         string switches[]         = {"NYNYNYNYNYNYNYNY",  "YNYNYNYNYNYNYNYN",  "NNNNNNNNNNNNNNNN",  "YNNNNNNNNNNNNNNN",  "NYNNNNNNNNNNNNNN",  "NNYNNNNNNNNNNNNN",  "NNNYNNNNNNNNNNNN",  "NNNNYNNNNNNNNNNN",  "NNNNNYNNNNNNNNNN",  "NNNNNNYNNNNNNNNN",  "NNNNNNNYNNNNNNNN",  "NNNNNNNNYNNNNNNN",  "NNNNNNNNNYNNNNNN",  "NNNNNNNNNNYNNNNN",  "NNNNNNNNNNNYNNNN",  "NNNNNNNNNNNNYNNN",  "NNNNNNNNNNNNNYNN",  "NNNNNNNNNNNNNNYN",  "NNNNNNNNNNNNNNNY"};
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
      case 4: {
         string initial            = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY";
         string switches[]         = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",  "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",  "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",  "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",  "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",  "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",  "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",  "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",  "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",  "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",  "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",  "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",  "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",  "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
      case 5: {
         string initial            = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN";
         string switches[]         = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",  "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",  "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",  "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",  "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",  "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",  "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",  "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",  "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",  "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",  "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",  "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",  "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",  "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",  "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",  "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",  "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",  "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",  "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",  "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         string initial            = ;
         string switches[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string initial            = ;
         string switches[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         string initial            = ;
         string switches[]         = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EllysLights().getMinimum( initial, vector <string>( switches, switches + ( sizeof switches / sizeof(string) ) ) ) );
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
