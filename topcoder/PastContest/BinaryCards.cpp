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

class BinaryCards {
public:
   long long largestNumber( long long A, long long B ) {
      llong res = B;
      for(llong i = 63; i > 0; --i) {
         if((A&(1LL<<i)) ^ (B&(1LL<<i))) {
            res|=((1LL<<i)-1);
            break;
         }
      }
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
         long long A               = 6LL;
         long long B               = 6LL;
         long long expected__      = 6LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
      case 1: {
         long long A               = 6LL;
         long long B               = 7LL;
         long long expected__      = 7LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
      case 2: {
         long long A               = 6LL;
         long long B               = 8LL;
         long long expected__      = 15LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
      case 3: {
         long long A               = 1LL;
         long long B               = 11LL;
         long long expected__      = 15LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
      case 4: {
         long long A               = 35LL;
         long long B               = 38LL;
         long long expected__      = 39LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
      case 5: {
         long long A               = 1125899906842630LL;
         long long B               = 1125899906842632LL;
         long long expected__      = 1125899906842639LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }

      // custom cases

/*
      case 6: {
         long long A               = LL;
         long long B               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
*/
/*
      case 7: {
         long long A               = LL;
         long long B               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
      }
*/
/*
      case 8: {
         long long A               = LL;
         long long B               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, BinaryCards().largestNumber( A, B ) );
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
