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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

class PalindromizationDiv2 {
public:

   bool ispal(int n) {
      int x=n, rev=0;
      while(x > 0) {
         rev*=10;
         rev+=(x%10);
         x/=10;
      }
      return n==rev;
   }

   int getMinimumCost(int X) {
      int res = 0;
      while(res < 10000) {
         if(ispal(X+res)) 
            return res;
         if(ispal(X-res)) 
            return res;
         res++;
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
         int X                     = 25;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
      case 1: {
         int X                     = 12321;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
      case 2: {
         int X                     = 40;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
      case 3: {
         int X                     = 2011;
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
      case 4: {
         int X                     = 0;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }

      // custom cases

/*
      case 5: {
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
*/
/*
      case 6: {
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
      }
*/
/*
      case 7: {
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PalindromizationDiv2().getMinimumCost( X ) );
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
