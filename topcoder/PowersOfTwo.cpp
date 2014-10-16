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


class PowersOfTwo {
public:
   long long count( vector<long long> powers ) {

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
         long powers[]             = {1,2};
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
      case 1: {
         long powers[]             = {1,1,1,1};
         long long expected__      = 5LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
      case 2: {
         long powers[]             = {1,2,2,2,4,4,16};
         long long expected__      = 32LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
      case 3: {
         long powers[]             = {1,32,1,16,32};
         long long expected__      = 18LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
      case 4: {
         long powers[]             = {1048576,1073741824,549755813888,70368744177664,4398046511104,262144,1048576,2097152,8796093022208,  1048576,1048576,35184372088832,2097152,256,256,256,262144,1048576,1048576,70368744177664,262144,1048576};
         long long expected__      = 18432LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         long powers[]             = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
*/
/*
      case 6: {
         long powers[]             = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
      }
*/
/*
      case 7: {
         long powers[]             = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, PowersOfTwo().count( vector<long long>( powers, powers + ( sizeof powers / sizeof(long) ) ) ) );
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
