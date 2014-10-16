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


class TheAlmostLuckyNumbersDivTwo {
public:

   bool almostlucky(int n) {
      int cnt = 0;
      int x = n;
      while(x > 0) { 
         int d = x%10;
         if(d!=4&&d!=7) cnt++;
         x/=10;
      }
      return cnt <= 1;
   }

   int find( int a, int b ) {
      int res = 0;
      for(int i = a; i <= b; ++i)
         if(almostlucky(i)) res++;
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
         int a                     = 4;
         int b                     = 7;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }
      case 1: {
         int a                     = 8;
         int b                     = 19;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }
      case 2: {
         int a                     = 28;
         int b                     = 33;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }
      case 3: {
         int a                     = 1234;
         int b                     = 4321;
         int expected__            = 36;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }

      // custom cases

/*
      case 4: {
         int a                     = ;
         int b                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }
*/
/*
      case 5: {
         int a                     = ;
         int b                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
      }
*/
/*
      case 6: {
         int a                     = ;
         int b                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivTwo().find( a, b ) );
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
