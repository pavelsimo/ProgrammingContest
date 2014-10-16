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

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)


class SparseFactorialDiv2 {
public:
   long long getCount( long long lo, long long hi, long long divisor ) {

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
         long long lo              = 4LL;
         long long hi              = 8LL;
         long long divisor         = 3LL;
         long long expected__      = 3LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
      case 1: {
         long long lo              = 9LL;
         long long hi              = 11LL;
         long long divisor         = 7LL;
         long long expected__      = 1LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
      case 2: {
         long long lo              = 1LL;
         long long hi              = 1000000000000LL;
         long long divisor         = 2LL;
         long long expected__      = 999999999999LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
      case 3: {
         long long lo              = 16LL;
         long long hi              = 26LL;
         long long divisor         = 11LL;
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
      case 4: {
         long long lo              = 10000LL;
         long long hi              = 20000LL;
         long long divisor         = 997LL;
         long long expected__      = 1211LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
      case 5: {
         long long lo              = 123456789LL;
         long long hi              = 987654321LL;
         long long divisor         = 71LL;
         long long expected__      = 438184668LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }

      // custom cases

/*
      case 6: {
         long long lo              = LL;
         long long hi              = LL;
         long long divisor         = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
*/
/*
      case 7: {
         long long lo              = LL;
         long long hi              = LL;
         long long divisor         = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
      }
*/
/*
      case 8: {
         long long lo              = LL;
         long long hi              = LL;
         long long divisor         = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, SparseFactorialDiv2().getCount( lo, hi, divisor ) );
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
