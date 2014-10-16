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


class PersistentNumber {
public:
   int getPersistence( int n ) {
      int res = 0;e
      while(n > 9) {
         int t = n, p = 1;
         while(t > 0) {
            p*=(t%10);
            t/=10;
         }
         n = p;
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
         int n                     = 99;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
      case 1: {
         int n                     = 268;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
      case 2: {
         int n                     = 6;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
      case 3: {
         int n                     = 68889789;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
      case 4: {
         int n                     = 86898;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }

      // custom cases

/*
      case 5: {
         int n                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
*/
/*
      case 6: {
         int n                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
      }
*/
/*
      case 7: {
         int n                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PersistentNumber().getPersistence( n ) );
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
